/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * net.c and net.h implement a struct to represent a 2-dimensional net of   *
 * nodes and connecting lines forming a polygon (without crossings if valid)*
 * interface functions are described below                                  *
 ***************************************************************************/

#ifndef _NET_H_
#define _NET_H_

#include "../pointList/pointList.c"
#include "../lineList/lineList.c"

struct Net_s 
{
    PointList_t *nodes;
    LineList_t *lines;

    double maxX, maxY, minX, minY;

    int numOfNodes;
};

typedef struct Net_s Net_t;

/*creates a new empty net, returning a pointer to it*/
Net_t *newNet();

/*fills the line list of the net using its points, also closes the line list (see lineList.h for further details)
 *returns 1 on success and 0 on fail*/
int generateLines(Net_t*);

/*checks if th net is valid (without crossings), also generates lines if this was not already done
 *returns 1 if the net is valid and 0 if it is invalid*/
int isValidNet(Net_t*);

/*prints all nodes of the net in a formatted table
 *returns 1 on success and 0 on fail*/
int printNet(Net_t*);

/*appends a point to the node list of a net, the order of appending matters for generating the lines
 *returns 1 on success and 0 on fail*/
int appendPoint(Net_t*, Point_t*);

/*checks if a Point is within a net, the net should be validated before
 *returns 1 if the point is in the net and 0 if it is not*/
int isWithinNet(Net_t*, Point_t*);

/*needed for isWithinNet, returns the number of intersections between a line and all net-lines, where the
 *given line is set between the point to be checked and a point that is definitely out of the net*/
int getRayCastIntersections(Net_t*, Point_t*);

#endif