#include <stdio.h>

void swap(int *a, int *b);
void sort(int ar[], int size);

int main(void)
{
    int num[100];
    int size;
    
    printf("Please enter size:");
    scanf("%d", &size);

    printf("Please enter numbers:");
    for (int i=0; i<size; i++)
        scanf("%d", &num[i]);

    sort(num, size);

    for (int i=0; i<size; i++)
        printf("%d ", num[i]);

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

void sort(int ar[], int size)
{
    for (int x=0; x<size-1; x++)
    {    for (int i=0; i<size-1-x; i++)
        {
            if (ar[i]>ar[i+1])
                swap(&ar[i], &ar[i+1]);
        }
    }
}