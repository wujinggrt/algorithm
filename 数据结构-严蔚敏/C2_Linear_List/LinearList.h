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
	SqList()
		: elem_(nullptr),
		length_(0),
		listsize_(0)
	{
		Status InitList();		
	}

	~SqList()
	{
		DestroyList();
	}

	Status InitList();

	Status DestroyList();

	Status ClearList();

	Status ListEmpty() const;

	int ListLength() const;

	// e返回第i个元素
	Status GetElem(int i, ElemType &e) const;

	// cpmare来比较两个元素的匹配问题
	// 返回e第一次出现的位置
	// 匹配失败，返回0
	int LocateElem(ElemType e, Status (*compare)(ElemType, ElemType)) const;

	// 返回前驱
	// cur_e不是第一个
	// 如果找不到cur_e，pre_e未定义
	Status PriorElem(ElemType cur_e, ElemType &pre_e) const;

	Status NextElem(ElemType cur_e, ElemType &next_e) const;

	// 在i之前插入，1 <= i <= ListLength(&L) + 1
	Status ListInsert(int i, ElemType e);

	Status ListDelete(int i, ElemType &e);

	Status ListTraverse(Status(*visit)(ElemType));

private:
	ElemType *elem_ = nullptr; // 存储空间基址
	int length_;
	int listsize_;
};

template <typename ElemType>
Status SqList<ElemType>::InitList()
{
    elem_ = new ElemType[LIST_INIT_SIZE];
    length_ = 0;
    listsize_ = LIST_INIT_SIZE;
    return OK;
}// InitList_Sq

template <typename ElemType>
Status SqList<ElemType>::DestroyList()
{
    if (elem_ != nullptr)
    {
        delete [] elem_;
    }
    elem_ = nullptr;
    length_ = 0;
    listsize_ = 0;
    return OK;
}// DestroyList_Sq

template <typename ElemType>
Status SqList<ElemType>::ClearList()
{
    length_ = 0;
    return OK;
}// ClearList_Sq

template <typename ElemType>
Status SqList<ElemType>::ListEmpty() const
{
    return (length_ == 0 ? OK : FLASE);
}// ListEmpty_Sq

template <typename ElemType>
int SqList<ElemType>::ListLength() const
{
    return length_;
} //ListLength_Sq

template <typename ElemType>
Status SqList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i <= 0 || i > length_)
    {
        return ERROR;
    }
    e = elem_[i - 1];
    return OK;
}
// GetElem_Sq

template <typename ElemType>
int SqList<ElemType>::LocateElem(ElemType e, Status (*compare)(ElemType, ElemType)) const
{
    for (int i = 0; i < length_; ++i)
    {
        if ((*compare)(e, *(elem_ + i)))
        {
            return i + 1;
        }
    }
    return 0;
}
// LocateElem_Sq

template <typename ElemType>
Status SqList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e) const
{
    for (int i = 1; i < length_; ++i)
    {
        if (elem_[i] == cur_e)
        {
            pre_e = elem_[i - 1];
            return OK;
        }
    }
    return ERROR;
}
// PriorElem_Sq

template <typename ElemType>
Status SqList<ElemType>::NextElem(ElemType cur_e, ElemType &next_e) const
{
    for (int i = 0; i < length_ - 1; ++i)
    {
        if (elem_[i] == cur_e)
        {
            next_e = elem_[i + 1];
            return OK;
        }
    }// for
    return ERROR;
}
// NextElem_Sq

template <typename ElemType>
Status SqList<ElemType>::ListInsert(int i, ElemType e)
{
    if (i < 1 || i > length_ + 1)
    {
        return ERROR;
    }
    if (length_ == listsize_)
    {
        ElemType *newbase = new ElemType[listsize_ + LISTINCREMENT];
        for (int j = 0; j < length_; ++j)
        {
            newbase[j] = elem_[j];
        }
        delete [] elem_;
        elem_ = newbase;
        listsize_ += LISTINCREMENT;
    }// if
    ++length_;
    // copy next.
    for (int j = length_ - 1; j > i - 1; --j)
    {
        elem_[j] = elem_[j - 1];
    }
    elem_[i - 1] = e;
    return OK;
}
// ListInsert

template <typename ElemType>
Status SqList<ElemType>::ListDelete(int i, ElemType &e)
{
    if (i < 1 || i > length_)
    {
        return ERROR;
    }
    --length_;
    for (int j = i - 1; j < length_; ++j)
    {
        elem_[j] = elem_[j + 1];
    }// for
    return OK;
}
// ListDelete

template <typename ElemType>
Status SqList<ElemType>::ListTraverse(Status(*visit)(ElemType))
{
    for (int i = 0; i < length_; ++i)
    {
        if (!(*visit)(elem_[i]))
        {
            return ERROR;
        }// if
    }// for
    return OK;
}
// ListTraverse

/*************************************
SqList
*************************************/

template <typename ElemType>
struct LNode
{
	ElemType data;
	LNode *prior = nullptr;
	LNode *next = nullptr;
};

template <typename ElemType>
class LinkList
{
public:
	LinkList()
	{}

	Status InitList()
	{
		if (head_ == nullptr && tail_ == nullptr)
		{
			head_ = new ElemType(); 
			tail_ = head_;
		}// if
	}
	
private:
	LNode<ElemType> *head_ = nullptr;
	LNode<ElemType> *tail_ = nullptr;
	int len_;
};

#endif