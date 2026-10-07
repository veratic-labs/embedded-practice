#include <stdio.h>
#include <stdlib.h>

#include "device.h"

int main(void)
{
    printf("Please enter the number of devices:");

    int num;
    scanf("%d", &num);

    Device *devices = malloc(num * sizeof(Device));

    printf("Please enter name, id, device type and data for each device:\n");
    for (int i = 0; i < num; i++)
    {
        printf("Device name:");
        scanf("%19s", devices[i].name);

        devices[i].id = i;

        printf("Device type (1:temperature 2:counter 3:switch):");
        int type;
        scanf("%d", &type);
        devices[i].type = (Devicetype)type;

        if (devices[i].type == TEMPERATURE)
        {
            printf("Please enter temperature data:");
            scanf("%lf", &devices[i].data.temperature);
        }

        else if (devices[i].type == COUNTER)
        {
            printf("Please enter counter data:");
            scanf("%d", &devices[i].data.count);
        }

        else if (devices[i].type == SWITCH)
        {
            printf("Please enter state:");
            scanf("%c", &devices[i].data.state);
        }
    }

    for (int i = 0; i < num; i++)
        print_device(&devices[i]);

    printf("Temperature type: %d\n", count_type(devices, num, TEMPERATURE));
    printf("Counter type: %d\n", count_type(devices, num, COUNTER));
    printf("Switch type: %d\n", count_type(devices, num, SWITCH));

    free(devices);

    return 0;

}

void print_device(Device *device)
{
    printf("Name: %s\n", device -> name);
    printf("id: %d\n", device -> id);
}

int count_type(Device devices[], int size, Devicetype type)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (devices[i].type == type)
            count += 1;
    }

    return count;
}