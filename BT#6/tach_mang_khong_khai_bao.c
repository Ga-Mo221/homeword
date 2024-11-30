#include <stdio.h>  
#include <conio.h>

int age[5];


void nhap()
{
    int stt=1;
    for (int i = 0; i < 5; i++)
    {
        printf("nhap vao mang %d: ",stt+=i);
        scanf("%d",&age[i]);
        stt = 1;
    }
}

void xuat()
{
    for (int i = 0; i<5; i++)
    {
        printf("%d ",age[i]);
    }
    printf("\n");
}

void tongCL()
{
    int sumC,sumL;
    for (int i = 0; i<5; i++)
    {
        if (age[i]%2==0)
        {
            sumC += age[i];
        }
        else
        {
            sumL +=age[i];
        }
    }
    printf("tong chan la: %d\n",sumC);
    printf("tong le la: %d\n",sumL);
}

void main()
{
    nhap();
    xuat();
    tongCL();
    getch();
}