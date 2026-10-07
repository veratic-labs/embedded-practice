#include <stdio.h>
#include <stdlib.h>

int sum(int ar[], int size);
int max(int aar[], int size);

int main(void)
{
    int num;
    int entry;

    printf("Please enter how many numbers you want to enter:");
    scanf("%d", &num);

    int *pn = malloc(num * sizeof(int));

    printf("Please enter %d numbers:", num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &entry);

        pn[i] = entry;
    }

    printf("Your list is: \n");

    for (int i = 0; i < num; i++)
        printf("%d ", pn[i]);

    printf("\n");

    printf("The maximum number is %d\n", max(pn, num));
    printf("The sum is %d\n", sum(pn, num));

    free(pn);

    return 0;
}

int sum(int ar[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
        total += ar[i];

    return total;
}

int max(int ar[], int size)
{
    int n = ar[1];

    for (int i = 1; i < size; i++)
    {
        if (ar[i] > n)
            n = ar[i+1];
    }

    return n;
}