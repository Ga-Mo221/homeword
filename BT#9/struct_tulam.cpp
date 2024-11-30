#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[25];
    float score;
};

typedef struct Student SV;

void nhap(SV *student)
{
    printf("moi ban nhap id: ");
    scanf(" %d", &student->id);
    getchar();
    printf("moi ban nhap ten: ");
    fgets(student->name, 25, stdin);
    student->name[strlen(student->name) - 1] = '\0';
    printf("moi ban nhap diem: ");
    scanf(" %f", &student->score);
}

void xuat(SV *student, int size)
{
    printf("\n\tBANG SINH VIEN\n");
    for (int i = 0; i < size; i++)
    {
        printf("%3d \t%-25s \t%3.1f\n", student[i].id, student[i].name, student[i].score);
    }
}

void bsl(int &size, SV *&student)
{
    printf("moi ban nhap so luong sinh vien: ");
    scanf("%d", &size);
    student = (SV*)malloc(size * sizeof(SV));
    for (int i = 0; i < size; i++)
    {
        printf("moi ban nhap sinh vien thu %d:\n", i + 1);
        nhap(&student[i]);
    }
}

void kbsl(int &size, SV *&student)
{
    char lua_chon;
    do
    {
        size++;
        student = (SV*)realloc(student, size * sizeof(SV));
        printf("moi ban nhap sinh vien thu %d:\n", size);
        nhap(&student[size - 1]);
        printf("ban co muon nhap them sinh vien khong? (y/n): ");
        scanf(" %c", &lua_chon);
    } while (lua_chon == 'y');
}

void menu(char choice, int &size, SV *&student)
{
    do
    {
        printf("ban co biet so luong sinh vien khong? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            printf("ban da chon y\n");
            bsl(size, student);
        }
        else if (choice == 'n')
        {
            printf("ban da chon n\n");
            kbsl(size, student);
        }
        else
        {
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 'y' && choice != 'n');
}

int main()
{
    int size = 0;
    SV *student = NULL;
    char choice = 'y';

    menu(choice, size, student);
    xuat(student, size);
    free(student);
    return 0;
}