#ifndef LINEAR_LIST_H__
#define LINEAR_LIST_H__

#include "../Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

template <typename ElemType>
class SqList
{
public:
	Status InitList();

	Status DestroyList();

	Status ClearList();

	Status ListEmpty();

	int ListLength();

	// e返回第i个元素
	Status GetElem(int i, ElemType &e);

	// cpmare来比较两个元素的匹配问题
	// 返回e第一次出现的位置
	// 匹配失败，返回0
	int LocateElem(ElemType e, Status (*compare)(ElemType, ElemType));

	// 返回前驱
	// cur_e不是第一个
	// 如果找不到cur_e，pre_e未定义
	Status PriorElem(ElemType cur_e, ElemType *pre_e);

	Status NextElem(ElemType cur_e, ElemType *next_e);

	// 在i之前插入，1 <= i <= ListLength(&L) + 1
	Status ListInsert_Sq(, int i, ElemType e);

	Status ListDelete_Sq(, int i, ElemType *e);

	Status ListTraverse(, Status(*visit)(ElemType));



private:
	ElemType *elem; // 存储空间基址
	int length;
	int listsize;
};


#endif