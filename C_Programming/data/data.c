#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("The content in data.txt is:\n");

    FILE *fp = fopen("data.txt", "r+");
    char content[50];

    while (fgets(content, sizeof(content), fp) != NULL)
        printf("%s", content);

    printf("\n");
    
    printf("The current position is:\n");
    long position = ftell(fp);
    printf("%ld\n", position);

    fseek(fp, 10, SEEK_SET);
    position = ftell(fp);
    printf("The new position is %ld\n", position);
    
    fprintf(fp, "CCCCC");

    fclose(fp);

    return 0;
}