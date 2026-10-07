#include <stdio.h>

int main(void)
{
    const int num = 7;
    int x;

    printf("Enter the number you guess:");
    
    while (x != num)
        scanf("%d", &x);

    printf("%d is the correct number\n", x);

    return 0;
}