#include <stdio.h>

int main(void)
{
    const int num = 29;
    int x = 0;
    int status;

    printf("Please enter the number you guess:");
    
    while (x != num)
    {
        status = scanf("%d", &x);

        if (status == 1)
            {
                if (x > num)
                    printf("%d is too big!\n", x);

                if (x < num)
                    printf("%d is too small!\n", x);

                if (x == num)
                    printf("%d is correct!\n", x);
            }

        else 
            printf("Please enter an integer!\n");
    }

    return 0;
}