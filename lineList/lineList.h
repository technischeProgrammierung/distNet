/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * lineList.c and lineList.h implement linked list of lineItems and needed  *
 * interface functions described below                                      *
 ***************************************************************************/

#ifndef _LINE_LIST_H_
#define _LINE_LIST_H_

#include "../lineItem/lineItem.c"

struct LineList_s
{
    LineItem_t *listStart;
};

typedef struct LineList_s LineList_t;

/*creates a new empty line List, returning a pointer to */
LineList_t *newLineList();

/*appends a LineItem to a LineList*/
void appendLineItem(LineList_t*, LineItem_t*);

/*closes the LineList by linking the last item of the list to the first one and therefore creates a ring-list*/
void closeLineList(LineList_t*);

#endif