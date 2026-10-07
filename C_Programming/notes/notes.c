#include <stdio.h>
#include <stdlib.h>

int menu(void);
void add_note(void);
void show_notes(void);

int main(void)
{
    int choice = 0;

    while (choice != 3)
    {
        choice = menu();

        if (choice == 1)
            add_note();

        else if (choice == 2)
            show_notes();
    }

    return 0;
}

int menu(void)
{
    printf("---Notes---\n");
    printf("1.Add a note\n");
    printf("2.Show all notes\n");
    printf("3.Exit\n");

    printf("Please enter your choice:");

    int result;

    scanf("%d", &result);

    while (getchar() != '\n')
        continue;

    return result;
}

void add_note(void)
{
    FILE *fp = fopen("notes.txt", "a");
    char note[50];

    printf("Please enter the notes you want to add:");

    fgets(note, sizeof(note), stdin);

    fprintf(fp, "%s", note);

    fclose(fp);
}

void show_notes(void)
{
    FILE *fp = fopen("notes.txt", "r");

    char notes[300];

    while (fgets(notes, sizeof(notes), fp) != NULL)
        printf("%s", notes);

    fclose(fp); 
}