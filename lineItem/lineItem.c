/********************************
 * author:                      *
 * Jonas Jansen                 *
 *                              *
 * description in header file   *
 *******************************/

#ifndef _LINE_ITEM_C_
#define _LINE_ITEM_C_

#include "lineItem.h"
#include <stdlib.h>


LineItem_t *newLineItem(Line_t* value)
{
    LineItem_t *dummy = (LineItem_t*) malloc(sizeof(LineItem_t));
    if(dummy != 0)
    {
        dummy->content = value;
        dummy->next = 0;
    }
    
    return dummy;
}

#endif