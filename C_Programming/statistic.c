#include <stdio.h>

int maximum(int ar[]);
int minimum(int ar[]);
void oddeven(int ar[],int *o, int *e);
float aver(int ar[]);

int main(void)
{
    int num[10];
    int max, min, odd, even;
    float average;
    
    //let user enter//
    printf("Please enter the number:");
    for (int i=0; i<10; i=i+1)
    {
        scanf("%d", &num[i]);
    }

    max = maximum(num);
    min = minimum(num);

    oddeven(num, &odd, &even);
    average = aver(num);

    printf("maximum is %d, minimum is %d, odd number %d, even number %d, average is %.2f\n", 
    max, min, odd, even, average);

    return 0;
}

int maximum(int ar[])
{
    int r;

    for (int i=0; i<10; i=i+1)
    {
        if (i==1)
            r = ar[i];
        
        else if (ar[i] > r)
            r = ar[i];
    }

    return r;
}

int minimum(int ar[])
{
    int r;

    for (int i=0; i<10; i=i+1)
    {
        if (i==0)
            r = ar[i];
        
        else if (ar[i] < r)
            r = ar[i];
    }

    return r;
}

void oddeven(int ar[], int *o, int *e)
{
    int odd = 0, even = 0;
    
    for (int i=0; i<10; i=i+1)
    {
        if (ar[i]%2==0)
            even = even+1;

        else
            odd = odd + 1;
    }

    *o = odd;
    *e = even;
}

float aver(int ar[])
{
    int sum = 0;
    float a;
    
    for (int i=0; i<10; i++)
    {
        sum += ar[i];
    }

    a = (float) sum/10;

    return a;
}