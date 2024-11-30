#include <stdio.h>
#include <conio.h>

void input(int arr[])
{
    for (int i = 0 ; i < 10; i++)
    {
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void timvahienthi(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 3 == 0 || arr[i] % 5 == 0)
        {
            printf("%4d", arr[i]);
        }
    }
}

void main()
{
    int list[10];
    input(list);
    timvahienthi(list);

    getch();
}