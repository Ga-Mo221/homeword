#include <stdio.h>
#include <conio.h>

//nhap kich thuoc
int siZe()
{
    int size;
    printf("\nNhap vao kich thuoc mang: ");
    scanf("%d",&size);
    return size;
}

//nhap phan tu
void input(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("List[%d] = ",i);
        scanf("%d",&arr[i]);
    }
}

//xuat mang ban dau
void printList(int arr[],int size)
{
    printf("\nMang ban dau ->");
    for (int i = 0 ; i < size ; i++)
    {
        printf("%3d",arr[i]);
    }
}

//chia mang chan
void MangCL(int arr[],int size)
{
    int sizeC=0,sizeL=0;
    //tinh so phan tu chan va le
    for (int i = 0 ; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sizeC += 1;
        }
        else
        {
            sizeL += 1;
        }
    }
    //khoi tao mang chan va le
    int ListC[sizeC];
    int ListL[sizeL];
    int sttC=0,sttL=0;
    //chia mang chan va le
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            ListC[sttC] = arr[i];
            sttC += 1;
        }
        else
        {
            ListL[sttL] = arr[i];
            sttL += 1;
        }
    }
    //hien thi mang Chan
    printf("\nMang chan ->");
    for(int i =0; i < sttC ; i++)
    {
        printf("%3d",ListC[i]);
    }
    //hien thi mang Le
    printf("\nMang chan ->");
    for(int i =0; i < sttL ; i++)
    {
        printf("%3d",ListL[i]);
    }
}

void main()
{
    int size = siZe();
    int List[size];
    input(List,size);
    printf("Chia mot mang thanh hai mang:");
    printf("\n");
    printList(List,size);
    MangCL(List,size);
    getch();
}