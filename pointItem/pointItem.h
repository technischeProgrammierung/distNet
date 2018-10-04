/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * pointItem.c and pointItem.h implement a struct needed for the linked     *
 * List pointList                                                           *
 ***************************************************************************/

#ifndef _POINT_ITEM_H_
#define _POINT_ITEM_H_

#include "../point/point.c"

struct PointItem_s
{
    Point_t* content;
    struct PointItem_s *next;
};
typedef struct PointItem_s PointItem_t;

/*creates a new PointItem for a pointList using a pointer to a point*/
PointItem_t *newPointItem(Point_t*);

#endif