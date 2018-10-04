/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _LINE_C_
#define _LINE_C_

#include "line.h"

Line_t *newLine(Point_t *firstPoint, Point_t *secondPoint)
{
    Line_t *dummy = (Line_t *)malloc(sizeof(Line_t));
    if (dummy != 0)
    {
        dummy->p1 = firstPoint;
        dummy->p2 = secondPoint;

        /* calculate line equation*/
        dummy->nx = (dummy->p1->y) - (dummy->p2->y);
        dummy->ny = (dummy->p2->x) - (dummy->p1->x);

        dummy->d = dummy->nx * dummy->p1->x + dummy->ny * dummy->p1->y;
    }

    return dummy;
}

double evalPoint(Line_t *line, Point_t *point)
{
    return line->nx * point->x + line->ny * point->y - line->d;
}

int haveCrossing(Line_t *l1, Line_t *l2)
{
    double test1 = evalPoint(l1, l2->p1) * evalPoint(l1, l2->p2);

    double test2 = evalPoint(l2, l1->p1) * evalPoint(l2, l1->p2);

    /* no crossing*/
    if (test1 > 0 || test2 > 0)
    {
        return 0;
    }

    /*one crossing*/
    return 1;
}

void printLine(Line_t* line)
{
    printf("(%.5f) * x + (%.5f) * y = %.5f\n",line->nx, line->ny, line->d);
}

#endif