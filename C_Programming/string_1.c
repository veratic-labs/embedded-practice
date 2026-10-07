#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50], copy[50];
    int length;

    printf("Please enter your name:");

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    length = strlen(name);

    if (length>0 && length<=20)
        printf("Username is valid\n");
    else
        printf("Username is not valid\n");

    strcpy(copy, name);

    printf("The copied string is %s", copy);

    return 0;
}