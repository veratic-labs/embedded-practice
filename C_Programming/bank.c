#include <stdio.h>

int menu(void);
void check_balance(float *p);
float save(float *p);
float withdraw(float *p);
void view_trans(float ar[], int times);

int main(void)
{
    float balance, trans[100];
    int choice, times = 0;
    
    printf("Please enter your initial deposit:");
    scanf("%f", &balance);

    while (1)
    {
        choice = menu();

        if (choice == 1)
            check_balance(&balance);

        else if (choice == 2)
        {
            trans[times] = save(&balance);
            times+=1;
        }
        
        else if (choice == 3)
        {    
            trans[times] = withdraw(&balance);
            times+=1;
        }

        else if (choice == 4)
            view_trans(trans, times);

        else if (choice == 0)
            break;
        
        getchar();
        getchar();
    }

    return 0;
    
}

int menu(void)
{
    int selection, status;

    printf("===== Bank System =====\n");
    printf("1.Check Balance\n");
    printf("2.Save\n");
    printf("3.Widthdraw\n");
    printf("4.View Transactions\n");
    printf("0.Exit\n");

    printf("Please enter your choice:");

    while (1)    
    {   
        status = scanf("%d", &selection);

        if (status && 0<=selection && selection <= 4)
            break;
        else
            printf("Please enter the correct number:");
    }
    
    return selection;
}

void check_balance(float *p)
{
    printf("Your deposit is %f\n", *p);
}

float save(float *p)
{
    float amount;
    
    printf("Enter the amount you want to save:");
    scanf("%f", &amount);

    *p += amount;

    return amount;
}

float withdraw(float *p)
{
    float amount;

    printf("Enter the amount you want to withdraw:");
    scanf("%f", &amount);

    if (amount > *p)
        printf("You do not have enough money!");
    else
    {    *p -= amount;
        return -amount;
    }
}

void view_trans(float ar[], int times)
{
    for (int i=0; i<times; i++)
        printf("%d  |  %f\n", i+1, ar[i]);
}