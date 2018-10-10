/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * point.c and pointList.h implement linked list of pointItems and needed   *
 * interface functions described below                                      *
 ***************************************************************************/

#ifndef _POINT_LIST_H_
#define _POINT_LIST_H_

#include "../pointItem/pointItem.c"

struct PointList_s
{
    PointItem_t *listStart;
};

typedef struct PointList_s PointList_t;

/* creates a new empty PointList returning a pointer to it*/
PointList_t *newPointList();

/*append a PointItem to a PointList*/
void appendPointItem(PointList_t*, PointItem_t*);

/*check if the list contains a Point that has equal X an Y Values as the Point given as a parameter*/
int contains(PointList_t*, Point_t*);

#endif