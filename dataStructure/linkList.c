
#include "structure.h"

//定义结构体
struct LNode {
	ElemType data; //数据域
	struct LNode *next;//指针域

};

typedef struct LNode  *LinkList; //定义LinkList

//LinkList L; //L为单链表的头指针


//构造空的线性表,参数 *L是个头指针
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(struct LNode)); //产生头节点并使L指向此头节点，*L头节点的指针
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
void GetElem(LinkList L,int i ,ElemType *e) {
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

