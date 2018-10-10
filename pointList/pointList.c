/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _POINT_LIST_C
#define _POINT_LIST_C

#include "pointList.h"

PointList_t *newPointList()
{
    PointList_t *dummy = (PointList_t*) malloc(sizeof(PointList_t));

    if(dummy != 0)
    {
        dummy->listStart = 0;
    }

    return dummy;
}

void appendPointItem(PointList_t* list, PointItem_t* item)
{
    if(list->listStart == 0)
    {
        list->listStart = item;
    }
    else
    {
        PointItem_t *ptr = list->listStart;

        while(ptr->next != 0)
        {
            ptr = ptr->next;
        }

        ptr->next = item;
    }
}

int contains(PointList_t* list, Point_t* point)
{
    PointItem_t *ptr = list->listStart;

        while(ptr != 0)
        {
            if(point->x == ptr->content->x && point->y == ptr->content->y)
            {
                return 1;
            }
            ptr = ptr->next;
        }

        return 0;
}

#endif