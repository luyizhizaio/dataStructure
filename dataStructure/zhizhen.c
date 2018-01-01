#include "structure.h"

typedef int ElemType;
typedef struct Node {
	ElemType elem;
	struct Node * next;
}Node, *LinkList;


//��ʼ������,����������Ϻ�,L��ָ��һ���յ�����,����ı�ָ���ֵ,����Ҫ��*L
void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}
//�������L,ʹL���±�Ϊ������,����������󲻻�ı�ָ��L��ֵ,ֻ��ı�ָ��L��ָ�������(��L->next��ֵ)
void ClearList(LinkList L)
{
	LinkList p;
	while (p = L->next)
		free(p);
}
//��������L,�ͷ�����L������ڴ�,ʹL��ֵ���±�ΪNULL,���Ի�ı�L��ֵ,����*L
void DestroyList(LinkList *L)
{
	LinkList p;
	while (p = (*L)->next)
		free(p);
	free(*L);
	*L = NULL;
}
void main()
{
	LinkList L = NULL; //Lͷָ��
	InitList(&L); // &L ��ʾָ��ͷָ���ָ��
	ClearList(L);
	DestroyList(&L);
}