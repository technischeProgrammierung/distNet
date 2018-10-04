/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * point.c and point.h implement a struct for defining a 2-dimensional Point*
 * and the needed interface functions described below                       *
 ***************************************************************************/
#ifndef _POINT_H_
#define _POINT_H_

struct Point_s
{
    double x;
    double y;
};
typedef struct Point_s Point_t;

/*creates a new point, defined by two doubles*/
Point_t *newPoint(double, double);

/*getter and setter for all attributes of a point*/
double getX(Point_t *);
double getY(Point_t *);
void setX(Point_t *, double);
void setY(Point_t *, double);

/* prints the attributes of a point to the console*/
void printPoint(Point_t *);

#endif