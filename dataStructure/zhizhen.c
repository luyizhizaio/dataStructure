#include "structure.h"

typedef int ElemType;
typedef struct Node {
	ElemType elem;
	struct Node * next;
}Node, *LinkList;


//初始化链表,函数调用完毕后,L会指向一个空的链表,即会改变指针的值,所以要用*L
void InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}
//清空链表L,使L重新变为空链表,函数调用完后不会改变指针L的值,只会改变指针L所指向的内容(即L->next的值)
void ClearList(LinkList L)
{
	LinkList p;
	while (p = L->next)
		free(p);
}
//销毁链表L,释放链表L申请的内存,使L的值重新变为NULL,所以会改变L的值,得用*L
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
	LinkList L = NULL; //L头指针
	InitList(&L); // &L 表示指向头指针的指针
	ClearList(L);
	DestroyList(&L);
}