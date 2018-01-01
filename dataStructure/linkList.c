#include "structure.h"

//定义结构体
struct LNode {
	ElemType data; //数据域
	struct LNode *next;//指针域

};

typedef struct LNode  *LinkList; //定义LinkList指针指向LNode

//LinkList L; //L为单链表的头指针


//构造空的线性表,参数 L是个头指针的指针
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(struct LNode)); //产生头节点并使*L指向头节点，*L头节点的指针
	if (!*L) {
		exit(OVERFLOW);
	}
	(*L)->next = NULL; //指针域为空

	return OK;
}

Status DestroyList(LinkList *L) {
	//销毁线性表
	LinkList q;
	while (*L) {
		q = (*L)->next;
		free(*L);
		*L = q;

	}
	return OK;
}

Status ClearList(LinkList L) {  /* 不改变L */
	//将L重置为空表

	LinkList p, q;
	p = L->next; /*p指向第一个节点*/
	while (p) { //未到表尾
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL; //头节点指针域为空
	return OK;
}
Status ListEmpty(LinkList L) {
	if (L->next) {
		return FALSE;
	}
	else {
		return TRUE;
	}

}

int  ListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}


/*L为带头节点的单链表的头指针，当第i个元素存在时，其值赋予e并返回OK,否则返回ERROR*/

Status GetElem(LinkList L,int i ,ElemType *e) {
	int j = i; //计数器
	LinkList p = L->next;
	while (p&& j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)/*第i个元素不存在*/
		return ERROR;
	*e = p->data;
	return OK;
}


int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
/*初始条件：线性表L已经存在，compare()是数据元素判断函数（满足为1，否则为0）
	操作结果： 返回L中第1个与e满足关系compare()的数据元素的为序。
	若这样的数据元素不存在，则返回0
*/
	int i = 0;
	LinkList  p = L->next;
	while (p) {
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e) {
	/*返回cur_e的前驱*/

	LinkList q, p = L->next;/*p指向第一个节点*/
	while (p->next) {
		q = p->next;
		if (q->data == cur_e) {
			*pre_e = p->data; //p就是要找的元素
			return OK;
		}
		p = q; /*p后移*/
	}
	return INFEASIBLE;

}

Status NextElem(LinkList L, ElemType cur_e, ElemType * next_e) {
	/*操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e 返回他的后继
	*/
	LinkList p = L->next;/*p指向第一个节点*/
	while (p->next) {

		if (p->data == cur_e) {
			*next_e = p->next->data;
			return OK;
		}
		p = p->next;


	}
	return INFEASIBLE;

}





Status ListInsert(LinkList L, int i, ElemType e) {

	/*在带头节点的单链表L中第i个位置之前插入元素e*/

	int j = 0;
	LinkList p = L,s;
	while (p&& j < i - 1) {/*寻找第i-1个节点*/
		p = p->next;
		j++;

	}
	if (!p || j > i - 1)/*i小于1，或者大于表长*/
		return ERROR;

	s = (LinkList)malloc(sizeof(struct LNode));/*生产新节点*/
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}

Status ListDelete(LinkList L, int i, ElemType *e) {
	/*在带头节点的单链表L中，删除第i个元素，并由e返回其值*/

	int j = 0;
	LinkList p = L, q;
	while (p->next && j < i - 1) { /*寻找第i个节点，并令p指向其前趋*/
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) /*删除位置不合理*/
		return ERROR;

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}


Status ListTraverse(LinkList L, void(*vi)(ElemType)) {
	/*vi的形参类型为ElemType，*/
	/*初始条件：线性表L已存在*/
	/*操作结果：依次对L的每个数据元素调用函数vi(),一旦vi失败，则操作失败*/
	LinkList p = L->next;/*p指向第一个节点*/
	while (p) {
		vi(p->data);
		p = p->next;

	}
	printf("\n");
	return OK;

}


void CreateList(LinkList *L, int n) {
	/*逆位序（头插法）输入n个元素的值，建立带表头结构的单链线性表L*/

	int i;
	LinkList p;
	*L = (LinkList)malloc(sizeof(struct LNode));
	(*L)->next = NULL; /*先建立一个带头节点的单链表*/
	printf("请输入%d个数据\n", n);

	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(struct LNode));/*生成新节点*/
		scanf("%d", &p->data);//输入元素值
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


void CreateList2(LinkList *L, int n) { /*L是指针变量*/
	/*正位序（尾插法）输入n个元素的值，建立带头节点的单链线性表*/
	int i;
	LinkList p, q;
	*L = (LinkList)malloc(sizeof(struct LNode));/*生成头结点*/
	(*L)->next = NULL;
	q = *L;
	printf("请输入%d个数据\n", n);
	for (i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(struct LNode));
		scanf("%d", &p->data);
		q->next = p;
		q = q->next;
	}
	p->next = NULL;
}


void main() {
	int n = 5;
	LinkList La, Lb, Lc;
	CreateList2(&La, n);

	int i = ListLength(La);

	printf("长度为%d个数据", i);


}




















































































