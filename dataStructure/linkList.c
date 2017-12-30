
#include "structure.h"

//����ṹ��
struct LNode {
	ElemType data; //������
	struct LNode *next;//ָ����

};

typedef struct LNode  *LinkList; //����LinkList

//LinkList L; //LΪ�������ͷָ��


//����յ����Ա�,���� *L�Ǹ�ͷָ��
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(struct LNode)); //����ͷ�ڵ㲢ʹLָ���ͷ�ڵ㣬*Lͷ�ڵ��ָ��
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
void GetElem(LinkList L,int i ,ElemType *e) {
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

