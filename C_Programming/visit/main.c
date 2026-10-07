#include <stdio.h>
#include "visit.h"

int main(void)
{
    extern int times;
    char entry;

    while (1)
    {
        printf("Enter y to visit (others to quit):");
        scanf(" %c", &entry);

        if (entry == 'y')
        {
            visit();
            printf("This is %dth visit\n", times);
        }

        else
            break;
    }

    printf("There are %d visits in total\n", times);

    return 0;
}