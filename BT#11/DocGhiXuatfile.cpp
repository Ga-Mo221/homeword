#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE * fptr;
    int id;
    char name[30];
    float salary;

    fptr = fopen("emp.txt", "a+");
    if (fptr == NULL)
    {
        printf("File does not exist \n");
        return 1;
    }

    //nhap vao so luong nhan vien
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    //nhap vao thong tin nhan vien
    for (int i = 0; i < n; i++)
    {
        printf("Employee %d\n", i+1);
        printf("Enter the employee ID: ");
        scanf("%d", &id);
        
        getchar();
        printf("Enter the name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name)-1] = '\0';

        printf("Enter the salary: ");
        scanf("%f", &salary);

        fprintf(fptr, "Name: %-25s\tID: %-10d\tSalary: %.2f\n", name, id, salary);
    }
    //đặt lại con trỏ về đầu file
    rewind(fptr);

    //đọc và in ra thông tin nhan vien
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);
    return 0;
}