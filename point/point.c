/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _POINT_C_
#define _POINT_C_

#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point_t *newPoint(double x, double y)
{
    Point_t *point = (Point_t*) malloc(sizeof(Point_t));
    if(point != 0)
    {
        point->x = x;
        point->y = y;
    }
    return point;
}


double getX(Point_t  *p)
{
    return p->x;
}

double getY(Point_t  *p)
{
    return p->y;
}

void setX(Point_t  *p, double x)
{
    p->x = x;
}

void setY(Point_t  *p, double y)
{
    p->y = y;
}

void printPoint(Point_t  *p)
{
    printf("(%lf | %lf) \n", p->x, p->y);

}

#endif
