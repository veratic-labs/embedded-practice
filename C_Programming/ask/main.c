#include <stdio.h>
#include "ask.h"

int main(void)
{
    char entry;

    while (1)
    {
        printf("Enter y to ask (Others to quit):");
        scanf(" %c", &entry);

        if (entry == 'y')
            ask();

        else
            break;
    }

    return 0;
}