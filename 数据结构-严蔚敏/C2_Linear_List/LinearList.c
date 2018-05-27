#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"

Status InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof (ElemType));
    if (! L->elem)
    {
        exit (OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}// InitList_Sq

Status DestroyList_Sq(SqList *L)
{
    if (L->elem != NULL || !L)
    {
        free (L->elem);
    }
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
    return OK;
}// DestroyList_Sq

Status ClearList_Sq(SqList *L)
{
    if (!L)
    {
        return ERROR;
    }
    L->length = 0;
    return OK;
}// ClearList_Sq

Status ListEmpty_Sq(SqList *L)
{
    if (!L)
    {
        return ERROR;
    }
    return (L->length == 0 ? OK : FLASE);
}// ListEmpty_Sq

int ListLength_Sq(SqList *L)
{
    if (!L)
    {
        return -1;
    }
    return L->length;
} //ListLength_Sq

Status GetElem_Sq(SqList *L, int i, ElemType *e)
{
    if (i <= 0 || i > L->length || !L)
    {
        return ERROR;
    }
    *e = *(L->elem + i - 1);
    return OK;
}
// GetElem_Sq

int LocateElem_Sq(SqList *L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    if (!L)
    {
        return ERROR;
    }
    ElemType *ptr = L->elem;
    for (int i = 0; i < L->length; ++i)
    {
        if ((*compare)(e, *(ptr + i)))
        {
            return i + 1;
        }
    }
    return 0;
}
// LocateElem_Sq

Status PriorElem_Sq(SqList *L, ElemType cur_e, ElemType *pre_e)
{
    if (!L)
    {
        return ERROR;
    }
    ElemType *ptr = L->elem;
    for (int i = 1; i < L->length; ++i)
    {
        if (*(ptr + i) == cur_e)
        {
            *pre_e = *(ptr + i - 1);
            return OK;
        }
    }
    return ERROR;
}
// PriorElem_Sq

Status NextElem_Sq(SqList *L, ElemType cur_e, ElemType *next_e)
{
    if (!L)
    {
        return ERROR;
    }
    ElemType *ptr = L->elem;
    for (int i = 0; i < L->length - 1; ++i)
    {
        if (*(ptr + i) == cur_e)
        {
            *next_e = *(ptr + i + 1);
            return OK;
        }
    }// for
    return ERROR;
}
// NextElem_Sq

Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
    if (!L || i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (L->length == L->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L->elem,
            (L->listsize + LISTINCREMENT) * sizeof (ElemType));
        if (!newbase)
        {
            exit(OVERFLOW);
        }// if
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }// if
    ElemType *pos = L->elem + i;
}




