/****************************************************************************
 * author:                                                                  *
 * Jonas Jansen                                                             *
 *                                                                          *
 * description:                                                             *
 * lineItem.c and lineItem.h implement a struct needed for the linked List  *
 * in lineItem.c and lineItem.h                                             *
 ***************************************************************************/


#ifndef _LINE_ITEM_H_
#define _LINE_ITEM_H_

#include "../line/line.c"

struct LineItem_s
{
    Line_t* content;
    struct LineItem_s *next;
};
typedef struct LineItem_s LineItem_t;

/* creates a new lineItem (for a lineList) using the line pointer, returns a pointer to the lineItem*/
LineItem_t *newLineItem(Line_t*);

#endif