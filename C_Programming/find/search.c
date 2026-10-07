int search(int ar[], int size, int x)
{
    int left = 0;
    int right = size-1;
    int n;

    while (left <= right)
    {
        n = (left + right)/2;
        if (ar[n] == x)
            return n;
        else if (ar[n]>x)
            right = n - 1;
        else
            left = n + 1;
    }

    return 0;
}