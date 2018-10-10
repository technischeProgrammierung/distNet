/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _NET_C_
#define _NET_C_

#include "net.h"
#include <stdio.h>

Net_t *newNet()
{
    Net_t *dummy = (Net_t *)malloc(sizeof(Net_t));
    if (dummy != 0)
    {
        dummy->numOfNodes = 0;
        dummy->nodes = newPointList();
        dummy->lines = newLineList();

        dummy->maxX = 0;
        dummy->maxY = 0;
        dummy->minX = 0;
        dummy->minY = 0;
    }

    return dummy;
}

int isValidNet(Net_t *net)
{
    if (net->numOfNodes <= 2)
    {
        printf("> Failed: Net does not contain enough nodes \n");
        return 0;
    }

    /*create Lines if this has not already been done*/
    if (net->lines->listStart == 0 && generateLines(net) == 0)
    {
        printf("> Failed: Generating Lines from Points failed \n");
        return 0;
    }

    /*compare each line with all other lines except itself and the adjacent lines*/
    LineItem_t *currentLine = net->lines->listStart;
    for (int i = 0; i < net->numOfNodes; i++)
    {
        LineItem_t *compareLine = currentLine->next->next;
        for(int j = 0; j < (net->numOfNodes -3 ); j++)
        {
            if(haveCrossing(currentLine->content, compareLine->content))
            {
                printf(">Failed: Lines have crossings \n");   
                return 0;
            }
            compareLine = compareLine->next;
        }
        currentLine = currentLine->next;
    }

    return 1;
}

int printNet(Net_t *net)
{
    PointItem_t *iterator = net->nodes->listStart;

    printf("-------------------------------\n");
    printf("| %-5s | %-8s | %-8s |\n", "Nr.", "X", "Y");
    printf("-------------------------------\n");

    for (int i = 0; i < net->numOfNodes; i++)
    {
        if (iterator == 0)
        {
            return 0;
        }
        printf("| %-5i | % .5f | % .5f |\n", i, iterator->content->x, iterator->content->y);

        iterator = iterator->next;
    }

    printf("-------------------------------\n");
    printf("| %-5s | % .5f | % .5f |\n","max",net->maxX,net->maxY);
    printf("| %-5s | % .5f | % .5f |\n","min",net->minX,net->minY);
    printf("-------------------------------\n");
    printf("| number of nodes: %10i |\n", net->numOfNodes);
    printf("-------------------------------\n");

    return 1;
}

int appendPoint(Net_t *net, Point_t *point)
{
    PointItem_t *dummy = newPointItem(point);
    if (dummy != 0)
    {
        appendPointItem(net->nodes, dummy);

        if(net->numOfNodes == 0)
        {
            net->maxX = getX(point);
            net->maxY = getY(point);
            net->minX = getX(point);
            net->minY = getY(point);
        }
        else
        {
            if(getX(point) > net->maxX) 
                net->maxX = getX(point);
            else if(getX(point) < net->minX)
                net->minX = getX(point);

            if(getY(point) > net->maxY) 
                net->maxY = getY(point);
            else if(getY(point) < net->minY)
                net->minY = getY(point);
        }

        net->numOfNodes++;
        return 1;
    }

    return 0;
}

int generateLines(Net_t *net)
{
    if (net->numOfNodes <= 1)
        return 0;

    PointItem_t *current = net->nodes->listStart;

    while (current->next != 0)
    {
        Line_t *line = newLine(current->content, current->next->content);
        LineItem_t *item = newLineItem(line);

        if (line == 0 || item == 0)
            return 0;

        appendLineItem(net->lines, item);

        current = current->next;
    }

    /*connect last point with first point*/
    Line_t *lastLine = newLine(current->content, net->nodes->listStart->content);
    LineItem_t *lastItem = newLineItem(lastLine);

    if (lastLine == 0 || lastItem == 0)
        return 0;

    appendLineItem(net->lines, lastItem);

    /*makes a ring list of the list*/
    closeLineList(net->lines);

    return 1;
}


int isWithinNet(Net_t* net, Point_t* point)
{
    if (net->lines->listStart == 0 || net->nodes->listStart == 0 || net->numOfNodes <= 2)
    {
        printf(">Check point in net failed: net not validated\n");
        return 0;
    }

    /*check if point is within max and min values of the net*/
    if( getX(point) > net->maxX || getX(point) < net->minX || getY(point) > net->maxY || getY(point) < net->minY)
    {
        return 0;
    }

    /*check if the point is equal to one of the nets nodes*/
    if(contains(net->nodes, point))
    {
        return 1;
    }

     /*if the ray between the point and a point outisde the polygon
     *has an uneven number of intersections, the point is in the Polygon -> return 1
     *otherwise it is outside the Polygon -> return 0*/
    return(getRayCastIntersections(net, point) % 2);
}


int getRayCastIntersections(Net_t* net, Point_t* point)
{
    /*TODO:
     * correct behaviour if the ray hits differnt kinds of vertexes
     * https://stackoverflow.com/questions/14130742/ray-through-vertex-special-case-when-detecting-point-in-polygon
    */
    
    /*create point that is definitely not in Polygon*/
    Point_t *outOfNet = newPoint((net->maxX + 1.0), point->y);
    Line_t *ray = newLine(point, outOfNet);

    int numOfCrossings = 0;

    LineItem_t *ptr = net->lines->listStart;

    /*check for intersections*/
    for(int i = 0; i < net->numOfNodes; i++)
    {
        if(haveCrossing(ptr->content, ray))
        {
            numOfCrossings++;
        }

        ptr = ptr->next;
    }

    free(outOfNet);
    free(ray);

    return numOfCrossings;
}

#endif