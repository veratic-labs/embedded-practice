#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x;
    int n;
    
    printf("please enter the base:");
    scanf("%d", &x);
    printf("please enter its power:");
    scanf("%d", &n);

    int result;
    result = power(x,n);

    printf("the value is %d\n", result);
    
    return 0;
}

int power(int x, int n)
{
    int i;
    int r;

    i = 0;
    r = 1;

    while (i < n)
    {
        r = r * x;
        i = i + 1;
    }

    return r;
}