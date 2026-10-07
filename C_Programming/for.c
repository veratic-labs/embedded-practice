#include <stdio.h>

int main(void)
{
    const int a = 16;
    int x;

    for (x = 0; x < a; x++)
        printf("%d", x);

    return 0;
}