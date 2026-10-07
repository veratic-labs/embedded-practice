#ifndef DEVICE_H
#define DEVICE_H

typedef enum
{
    TEMPERATURE = 1,
    COUNTER,
    SWITCH
} Devicetype;

typedef union
{
    double temperature;
    int count;
    char state;
} Devicedata;

typedef struct 
{
    char name[20];
    int id;
    Devicetype type;
    Devicedata data;
} Device;

void print_device(Device *device);
int count_type(Device devices[], int size, Devicetype type);

#endif