/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _LINE_LIST_C
#define _LINE_LIST_C

#include "lineList.h"

LineList_t *newLineList()
{
    LineList_t *dummy = (LineList_t*) malloc(sizeof(LineList_t));

    if(dummy != 0)
    {
        dummy->listStart = 0;
    }

    return dummy;
}

void appendLineItem(LineList_t* list, LineItem_t* item)
{
    if(list->listStart == 0)
    {
        list->listStart = item;
    }
    else
    {
        LineItem_t *ptr = list->listStart;

        while(ptr->next != 0)
        {
            ptr = ptr->next;
        }

        ptr->next = item;
    }
}

void closeLineList( LineList_t *list)
{
    LineItem_t *ptr = list->listStart;

    if(ptr == 0) return;

    while(ptr != 0)
    {
        if(ptr->next == 0)
        {
            ptr->next = list->listStart;

            return;
        }
        ptr = ptr->next;
    }
}

#endif