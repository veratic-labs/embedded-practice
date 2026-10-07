#include <stdio.h>
#include "bsort.h"
#include "search.h"

#define SIZE 10

int main(void)
{
    //initialise and let user enter
    int num[SIZE];
    int x;
    int n;

    printf("Please enter %d numbers:", SIZE);

    for (int i=0; i<SIZE; i++)
        scanf("%d", &num[i]);

    printf("Please enter the number you want to seaarch:");
    scanf("%d", &x);

    //sort and search
    bsort(num, SIZE);
    n = search(num, SIZE, x);
    
    if (n != 0)
        printf("%d is in the array, it is in the %dth position\n", x, n);

    else
        printf("%d is not in the array\n", x);

    return 0;
}