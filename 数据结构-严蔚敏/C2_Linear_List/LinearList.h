#ifndef LINEAR_LIST_H__
#define LINEAR_LIST_H__

#include "../Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct
{
	ElemType *elem; // 存储空间基址
	int length;
	int listsize;
} SqList;

Status InitList_Sq(SqList *L);

Status DestroyList(SqList *L);

Status ClearList_Sq(SqList *L);

Status ListEmpty_Sq(SqList *L);

int ListLength_Sq(SqList *L);

// e返回第i个元素
Status GetElem_Sq(SqList *L, int i, ElemType *e);

int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType));

Status PriorElem_Sq(SqList *L, ElemType cur_e, ElemType *pre_e);

Status NextElem_Sq(SqList *L, ElemType cur_e, ElemType *next_e);

Status ListInsert_Sq(SqList *L, int i, ElemType e);

Status ListDelete_Sq(SqList *L, int i, ElemType *e);

Status ListTraverse(SqList *L, Status(*visit)(ElemType));

#endif