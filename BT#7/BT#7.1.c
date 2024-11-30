#include <stdio.h>
#include <conio.h>

//nhap
void inputArray(int arr[],int size)
{
    for (int i = 0 ; i < size ; i++ )
    {
        scanf("%d",&arr[i]);
    }
}

//xuat
void printArray(int arr[],  int size)
{
    for (int i = 0; i < size; i++ )
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int kichthuoc;
    printf("moi ban nhap vao kich thuoc: ");
    scanf("%d",&kichthuoc);
    int myArray[kichthuoc];
    inputArray(myArray,kichthuoc);
    printArray(myArray,kichthuoc);

    getch();
    return 0;
}