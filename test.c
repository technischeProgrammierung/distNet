#include "./net/net.c"
#include <stdio.h>

int main()
{
    Point_t netNodes[5];
    Point_t pointToBeChecked;
    Net_t net  = *newNet();

    netNodes[0] = *newPoint(0,0);
    netNodes[1] = *newPoint(5,0);
    netNodes[2] = *newPoint(5,5);
    netNodes[3] = *newPoint(2.5,4);
    netNodes[4] = *newPoint(0,5);

    pointToBeChecked = *newPoint(2.5,4.2);

    for(int i = 0; i < 5; i++)
    {
        appendPoint(&net, &netNodes[i]);
    }

    printNet(&net);
    
    if(isValidNet(&net))
    {
        LineItem_t *ptr = net.lines->listStart;
        printf("The entered net is valid!\n");

        if(isWithinNet(&net, &pointToBeChecked))
        {
            printf("The point ");
            printPoint(&pointToBeChecked);
            printf("is within the net! \n");
        }
        else
        {
            printf("The point ");
            printPoint(&pointToBeChecked);
            printf("is NOT within the net! \n");
        }
    }
    else
    {
        printf("No valid net \n");
    }
    

    return 0;
}