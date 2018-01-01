#include "structure.h"

//����ṹ��
struct LNode {
	ElemType data; //������
	struct LNode *next;//ָ����

};

typedef struct LNode  *LinkList; //����LinkListָ��ָ��LNode

//LinkList L; //LΪ�������ͷָ��


//����յ����Ա�,���� L�Ǹ�ͷָ���ָ��
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(struct LNode)); //����ͷ�ڵ㲢ʹ*Lָ��ͷ�ڵ㣬*Lͷ�ڵ��ָ��
	if (!*L) {
		exit(OVERFLOW);
	}
	(*L)->next = NULL; //ָ����Ϊ��

	return OK;
}

Status DestroyList(LinkList *L) {
	//�������Ա�
	LinkList q;
	while (*L) {
		q = (*L)->next;
		free(*L);
		*L = q;

	}
	return OK;
}

Status ClearList(LinkList L) {  /* ���ı�L */
	//��L����Ϊ�ձ�

	LinkList p, q;
	p = L->next; /*pָ���һ���ڵ�*/
	while (p) { //δ����β
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL; //ͷ�ڵ�ָ����Ϊ��
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


/*LΪ��ͷ�ڵ�ĵ������ͷָ�룬����i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�ERROR*/

Status GetElem(LinkList L,int i ,ElemType *e) {
	int j = i; //������
	LinkList p = L->next;
	while (p&& j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)/*��i��Ԫ�ز�����*/
		return ERROR;
	*e = p->data;
	return OK;
}


int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
/*��ʼ���������Ա�L�Ѿ����ڣ�compare()������Ԫ���жϺ���������Ϊ1������Ϊ0��
	��������� ����L�е�1����e�����ϵcompare()������Ԫ�ص�Ϊ��
	������������Ԫ�ز����ڣ��򷵻�0
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
	/*����cur_e��ǰ��*/

	LinkList q, p = L->next;/*pָ���һ���ڵ�*/
	while (p->next) {
		q = p->next;
		if (q->data == cur_e) {
			*pre_e = p->data; //p����Ҫ�ҵ�Ԫ��
			return OK;
		}
		p = q; /*p����*/
	}
	return INFEASIBLE;

}

Status NextElem(LinkList L, ElemType cur_e, ElemType * next_e) {
	/*�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e �������ĺ��
	*/
	LinkList p = L->next;/*pָ���һ���ڵ�*/
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

	/*�ڴ�ͷ�ڵ�ĵ�����L�е�i��λ��֮ǰ����Ԫ��e*/

	int j = 0;
	LinkList p = L,s;
	while (p&& j < i - 1) {/*Ѱ�ҵ�i-1���ڵ�*/
		p = p->next;
		j++;

	}
	if (!p || j > i - 1)/*iС��1�����ߴ��ڱ�*/
		return ERROR;

	s = (LinkList)malloc(sizeof(struct LNode));/*�����½ڵ�*/
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}

Status ListDelete(LinkList L, int i, ElemType *e) {
	/*�ڴ�ͷ�ڵ�ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ*/

	int j = 0;
	LinkList p = L, q;
	while (p->next && j < i - 1) { /*Ѱ�ҵ�i���ڵ㣬����pָ����ǰ��*/
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) /*ɾ��λ�ò�����*/
		return ERROR;

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}


Status ListTraverse(LinkList L, void(*vi)(ElemType)) {
	/*vi���β�����ΪElemType��*/
	/*��ʼ���������Ա�L�Ѵ���*/
	/*������������ζ�L��ÿ������Ԫ�ص��ú���vi(),һ��viʧ�ܣ������ʧ��*/
	LinkList p = L->next;/*pָ���һ���ڵ�*/
	while (p) {
		vi(p->data);
		p = p->next;

	}
	printf("\n");
	return OK;

}


void CreateList(LinkList *L, int n) {
	/*��λ��ͷ�巨������n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�L*/

	int i;
	LinkList p;
	*L = (LinkList)malloc(sizeof(struct LNode));
	(*L)->next = NULL; /*�Ƚ���һ����ͷ�ڵ�ĵ�����*/
	printf("������%d������\n", n);

	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(struct LNode));/*�����½ڵ�*/
		scanf("%d", &p->data);//����Ԫ��ֵ
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


void CreateList2(LinkList *L, int n) { /*L��ָ�����*/
	/*��λ��β�巨������n��Ԫ�ص�ֵ��������ͷ�ڵ�ĵ������Ա�*/
	int i;
	LinkList p, q;
	*L = (LinkList)malloc(sizeof(struct LNode));/*����ͷ���*/
	(*L)->next = NULL;
	q = *L;
	printf("������%d������\n", n);
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

	printf("����Ϊ%d������", i);


}




















































































