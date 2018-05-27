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

Status LocateElem_Sq(SqList *L, ElemType e, Status (*cpmare)(ElemType))
{
    if (!L)
    {
        return ERROR;
    }
    
}







