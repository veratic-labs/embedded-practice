#include <stdio.h>
#include <string.h>

#define NUM 5

struct student
{
    char name[30];
    int id;
    int score;
};

double average(struct student ar[NUM]);
void best_student(struct student ar[NUM]);

int main(void)
{
    struct student students[NUM];
    
    printf("Please enter five students' name, id and score:");

    for (int i = 0; i < NUM; i++)
    {
        scanf("%29s", students[i].name);
        scanf("%d", &students[i].id);
        scanf("%d", &students[i].score);
    }

    printf("The average score is %f", average(students));

    best_student(students);

    return 0;
}

double average(struct student ar[NUM])
{
    int total = 0;

    for (int i = 0; i < NUM; i++)
        total += ar[i].score;

    double result = (double)total/NUM;

    return result;
}

void best_student(struct student ar[NUM])
{
    int best_i = 0;

    for (int i = 0; i < NUM; i++)
    {
        if (ar[i].score > ar[best_i].score)
            best_i = i;
    }

    printf("The best student is %s, his id is %d, his score is %d", 
        ar[best_i].name, ar[best_i].id, ar[best_i].score);
}