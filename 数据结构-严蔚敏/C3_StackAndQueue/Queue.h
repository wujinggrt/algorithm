#ifndef QUEUE_H__
#define QUEUE_H__

#include "../Status.h"

#define MAX_QUEUE_SIZE 100

template<typename T>
class SqQueue
{
public:
    SqQueue()
    {
        InitQueue();
    }

    Status InitQueue(0)
    {
        if (!base_)
        {
            base_ = new T[MAX_QUEUE_SIZE];
        }
        front_ = rear_ = 0;
    }
    // InitQueue

    Status DestroyQueue()
    {
        if (!base_)
        {
            delete [] base_;
        }
        base_ = nullptr;
        front_ = rear_ = 0;
    }


private:
    T *base_ = nullptr;
    int front_;
    int rear_;
};
// SqQueue

#endif