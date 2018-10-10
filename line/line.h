/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * line.c and line.h implement a struct for defining 2-dimensional lines    *
 * and its interface functions described below                              *
 ***************************************************************************/

#ifndef _LINE_H_
#define _LINE_H_

#include "../point/point.c"
#include <stdlib.h>

struct Line_s
{
    Point_t *p1, *p2;
    double nx, ny, d;
    /* 
    * Equation:
    * nx * X + ny * Y = d;
    */
   

};
typedef struct Line_s Line_t;


/*creates a new line using two points, returns a pointer to this line*/
Line_t *newLine(Point_t*, Point_t*);

/*evaluates if a point is below above or on a line, returns a negative, positive or zero value accordingly*/
double evalPoint(Line_t*, Point_t*);

/*checks if two lines cross each other, if there is an intersection returns 1, otherwise returns 0*/
int haveIntersection(Line_t*, Line_t*);

/*calculates the intersection of two lines*/
Point_t* calcIntersection(Line_t*, Line_t*);

/*prints a line in the form of an equation as mentioned above*/
void printLine(Line_t*);


#endif