#include <stdio.h>
#include <stdlib.h>

struct product
{
    char name[20];
    double price;
    int quantity;
};

void print_products(struct product ar[], int size);
double total_value(struct product ar[], int size);

int main(void)
{
    printf("PLease enter the number of product:");
    int num;
    scanf("%d", &num);

    struct product *p = malloc(num * sizeof(struct product));

    printf("PLease enter the name, price and quantity for each product:");

    for (int i = 0; i < num; i++)
        scanf("%19s %lf %d", p[i].name, &p[i].price, &p[i].quantity);

    print_products(p, num);

    double total = total_value(p, num);
    printf("The total value is %f\n", total);

    free(p);

    return 0;
}

void print_products(struct product ar[], int size)
{
    for (int i = 0; i < size; i++)
    {
      printf("Product %s has price %f and quantity %d\n",
        ar[i].name, ar[i].price, ar[i].quantity);
    }
}

double total_value(struct product ar[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
        total += ar[i].price * ar[i].quantity;

    return total;
}