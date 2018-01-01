#include "structure.h"

#define LISTSIZE 100

typedef struct {
	int elem[LISTSIZE];
	int length;
}Sqlist2;




#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType *elem; //存储空间基址
	int length; //当前长度
	int listsize; //当前分配的容量，以sizeof(ElemType)为单位


} Sqlist; //顺序表


//初始化 L表示指针  等价于c++里的 &L
Status InitList_sq(Sqlist *L) {
	(*L).elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;

}

//查找，时间性能O(n)
int LocateElem_sq(Sqlist L, ElemType x) {
	int i=0;
	while (i <= L.length-1 && L.elem[i] != x) i++;

	if (i > L.length - 1) return ERROR;
	else return i;

}

//插入，在顺序表L的第i个元素之前插入元素
Status ListInsert_sq(Sqlist *L, int i, ElemType e) {

	ElemType *newbase, *q, *p; //存储空间基址
	
	//合法位置判断
	if(i <1 || i >(*L).length + 1){
		return ERROR;
	}
	if ((*L).length >= (*L).listsize) { //增加分配
		newbase = (ElemType *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
	}
	if (!newbase) {
		exit(OVERFLOW);
	}
	(*L).elem = newbase; //新基址
	(*L).listsize += LISTINCREMENT; //增加存储容量

	q = (*L).elem + i - 1; //插入位置
	for (p = (*L).elem + (*L).length - 1; p >= q; --p) { //p为表尾元素位置
		*(p + 1) = *p; //插入位置及之后的元素右移
	}
	*q = e; //插入e
	++(*L).length; //表长加1
	return OK;
}

//删除操作
Status listDelete_sq(Sqlist *L, int i, ElemType *e) {
	/*初始条件： 顺序表存在 ，1<= i <= ListLength(L)
	操作结果： 删除L的第i个数据元素并用e返回其值，L长度减1
	*/
	ElemType *p, *q;
	if (i<1 || i>(*L).length) return ERROR;
	p = (*L).elem + i - 1;//删除元素的位置
	*e = *p; //被删除元素的值赋予e
	q = (*L).elem + (*L).length - 1; //表尾元素位置
	for (++p; p <= q; ++p)//被删除元素之后的元素左移
		*(p - 1) = *p;
	(*L).length--;//表长减1

	return OK;
} 

//遍历操作
Status ListTraverse_sq(Sqlist L, void(*vi)(ElemType *)) {
	/* 初始条件：顺序线性表L已存在 */     
	/* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */   
	/*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */

	ElemType *p;
	int i;
	p = L.elem;
	for (i = 1; i <= L.length; i++)
		vi(p++);
	printf("\n");
	return OK;



}




/*main() {
	Sqlist sl;
	Status i;
	 i = InitList(&sl); //&sl取一个变量的地址
	 printf("start");
	
	 
	 if(i == 1)//创建成功
		 printf("end");
			   //for()
}*/

































