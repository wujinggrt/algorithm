#ifndef STACK_H__
#define STACK_H__

#include "../Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

template <typename T>
class SqStack
{
public:
	SqStack()
		: stacksize_(0)
	{
		InitStack();
	}

	SqStack(const int size)
		: base_(new  T[size]),
		top_(base_),
		stacksize_(size)
	{
	}

	~SqStack()
	{
		if (stacksize_ != 0)
		{
			DestroyStack();
		}
	}

	Status InitStack()
	{
        if (base_ == nullptr)
		{
            base_= new T[STACK_INIT_SIZE];
            top_ = base_;
            stacksize_ = STACK_INIT_SIZE;
        }
		return OK;
	}
	// InitStack

	Status DestroyStack()
	{
        if (base_ != nullptr)
		{
            delete [] base_;
            base_ = top_ = nullptr;
            stacksize_ = 0;
        }
        return OK;
	}
	// DestroyStack

	Status ClearStack()
	{
		top_ = base_;
		return OK;
	}
	// ClearStack

	bool StackEmpty() const
	{
		return base_ == top_ ? true : false;
	}
	// StackEmpty

	int StackLength()
	{
		return top_ - base_;
	}
	// StackLength

	Status GetTop_(T &e) const
	{
		if (StackEmpty()) // should confirm the method const first
		{
			return ERROR;
		}
		e = *(top_ - 1);
		return TRUE;
	}
	// GetTop_

	Status Push(const T e)
	{
		// realloc
		if (top_ - base_ == stacksize_) // after base_[stacksize_ - 1]
		{
			auto newBase_ = new T[stacksize_ + STACKINCREMENT];
			top_ = nullptr;
			for (int i = 0; i < stacksize_; ++i)
			{
				newBase_[i] = base_[i];
			}
			delete [] base_;
			base_ = newBase_;
			top_ = base_ + stacksize_;
			stacksize_ += STACKINCREMENT;
		}
		*top_ = e;
		++top_;
		return OK;
	}
	// Push

	Status Pop(T &e)
	{
		if (StackEmpty())
		{
			return ERROR;
		}
		e = *--top_;
		return OK;
	}
	// Pop

	Status StackTraverse();

private:
	T *base_ = nullptr;
	T *top_ = nullptr;
	int stacksize_;
};
// Class SqStack

/***********************
 * SqStack
***********************/

template<typename ElemType>
struct Node
{
    ElemType data;
    Node *bext = nullptr;
};
// Node

template<typename ElemType>
class LinkStack
{
public:
    LinkStack();

    Status InitStack()
    {
        if (!base_)
        {
            base_ = new Node<ElemType>();
            top_ = base_;
        }
    }
    // IniStack



private:
    Node<ElemType> *base_ = nullptr;
    Node<ElemType> *top_ = nullptr;

};
// LinkStack

/***********************
 * LinkStack
***********************/

#endif