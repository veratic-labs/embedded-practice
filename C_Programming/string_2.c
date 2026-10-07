#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[50], confirmed[50];

    printf("Please enter your password:");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    printf("Please confirm your password:");
    fgets(confirmed, sizeof(confirmed), stdin);
    confirmed[strcspn(confirmed, "\n")] = '\0';

    if (strcmp(password, confirmed) == 0)
        printf("Password confirmed!\n");
    else
        printf("Passwords are different!\n");

    return 0;
}