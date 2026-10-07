#include <stdio.h>
#include <stdlib.h>

#define NUM 5

int main(void)
{
    FILE *fp = fopen("score.txt", "w");

    char name[50];
    int score;

    printf("Please enter %d names and scores:", NUM);
    
    for (int i = 0; i < NUM; i++)
    {
        scanf("%49s %d", name, &score);
        fprintf(fp, "%s %d\n", name, score);
    }

    printf("Saving complete!\n");

    fclose(fp);

    printf("Your file contains:\n");

    fp = fopen("score.txt", "r");

    for (int i = 0; i < NUM; i++)
    {
        fscanf(fp, "%49s %d\n", name, &score);
        printf("%s %d\n", name, score);
    }

    return 0;
}