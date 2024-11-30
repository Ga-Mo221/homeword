#include <stdio.h>  
#include <conio.h>

int age[5];

void nhap(int a[])
{
    int stt=1;
    for (int i = 0; i < 5; i++)
    {
        printf("nhap vao mang %d: ",stt+=i);
        scanf("%d",&a[i]);
        stt = 1;
    }
}

void xuat(int a[])
{
    for (int i = 0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void tongCL(int a[])
{
    int sumC,sumL;
    for (int i = 0; i<5; i++)
    {
        if (a[i]%2==0)
        {
            sumC += a[i];
        }
        else
        {
            sumL +=a[i];
        }
    }
    printf("tong chan la: %d\n",sumC);
    printf("tong le la: %d\n",sumL);
}

void main()
{
    nhap(age);
    xuat(age);
    tongCL(age);
    getch();
}