#include <stdio.h>
#include <string.h>

int main(void)
{
    char base[50] = "home/simon/";
    char file[50];

    printf("Please enter file name:");
    fgets(file, sizeof(file), stdin);
    file[strcspn(file, "\n")] = '\0';

    strcat(base, file);

    printf("Your file path is %s", base);

    return 0;
}