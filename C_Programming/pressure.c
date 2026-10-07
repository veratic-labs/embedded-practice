#include <stdio.h>

#define density 1
#define gravity 9.81

int main(void)
{
    float height;

    printf("please enter the height of water:");
    scanf("%f", &height);

    float pressure;
    pressure = density * gravity * height;

    printf("the pressure is %f\n", pressure);

    return 0;
}