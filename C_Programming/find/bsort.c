void change(int *a, int *b);

void bsort(int ar[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int x = 0; x < size-i; x++)
        {    
            if (ar[x] > ar[x+1])
                change(&ar[x], &ar[x+1]);
        }
    }
}

void change(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}