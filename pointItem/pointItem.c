/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _POINT_ITEM_C_
#define _POINT_ITEM_C_

#include "pointItem.h"
#include <stdlib.h>


PointItem_t *newPointItem(Point_t* value)
{
    PointItem_t *dummy = (PointItem_t*) malloc(sizeof(PointItem_t));
    if(dummy != 0)
    {
        dummy->content = value;
        dummy->next = 0;
    }
    
    return dummy;
}

#endif