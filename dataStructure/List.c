

#include "structure.h"

#define LISTSIZE 100

typedef struct {
	int elem[LISTSIZE];
	int length;
}Sqlist2;




#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
	ElemType *elem; //�洢�ռ��ַ
	int length; //��ǰ����
	int listsize; //��ǰ�������������sizeof(ElemType)Ϊ��λ


} Sqlist; //˳���


//��ʼ�� *L��ʾָ��  �ȼ���c++��� &L
Status InitList(Sqlist *L) {
	(*L).elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;

}

//���ң�ʱ������O(n)
int LocateElem(Sqlist L, ElemType x) {
	int i=0;
	while (i <= L.length-1 && L.elem[i] != x) i++;

	if (i > L.length - 1) return ERROR;
	else return i;

}

//���룬��˳���L�ĵ�i��Ԫ��֮ǰ����Ԫ��
Status ListInsert(Sqlist *L, int i, ElemType e) {

	ElemType *newbase, *q, *p; //�洢�ռ��ַ
	
	//�Ϸ�λ���ж�
	if(i <1 || i >(*L).length + 1){
		return ERROR;
	}
	if ((*L).length >= (*L).listsize) { //���ӷ���
		newbase = (ElemType *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
	}
	if (!newbase) {
		exit(OVERFLOW);
	}
	(*L).elem = newbase; //�»�ַ
	(*L).listsize += LISTINCREMENT; //���Ӵ洢����

	q = (*L).elem + i - 1; //����λ��
	for (p = (*L).elem + (*L).length - 1; p >= q; --p) { //pΪ��βԪ��λ��
		*(p + 1) = *p; //����λ�ü�֮���Ԫ������
	}
	*q = e; //����e
	++(*L).length; //������1
	return OK;
}

//ɾ������
Status listDelete(Sqlist *L, int i, ElemType *e) {
	/*��ʼ������ ˳������� ��1<= i <= ListLength(L)
	��������� ɾ��L�ĵ�i������Ԫ�ز���e������ֵ��L���ȼ�1
	*/
	ElemType *p, *q;
	if (i<1 || i>(*L).length) return ERROR;
	p = (*L).elem + i - 1;//ɾ��Ԫ�ص�λ��
	*e = *p; //��ɾ��Ԫ�ص�ֵ����e
	q = (*L).elem + (*L).length - 1; //��βԪ��λ��
	for (++p; p <= q; ++p)//��ɾ��Ԫ��֮���Ԫ������
		*(p - 1) = *p;
	(*L).length--;//������1

	return OK;
}



main() {
	Sqlist sl;
	Status i;
	 i = InitList(&sl); //&slȡһ�������ĵ�ַ
	 printf("start");
	
	 
	 if(i == 1)//�����ɹ�
		 printf("end");
			   //for()
}
































