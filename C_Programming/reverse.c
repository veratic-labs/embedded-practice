#include <stdio.h>
#define SIZE 10

void swap(int *a, int *b);

int main(void)
{
    int num[SIZE] = {12,34,56,24,68,79,24,35,57,34};

    for (int i = 0; i < SIZE/2; i++)
    {
        swap(&num[i], &num[SIZE-1-i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}