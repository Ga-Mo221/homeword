#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

//tim kiem
bool Timkiem(int a[], int n, int x) // Thay đổi kiểu trả về thành bool
{
    for (int i = 0; i < n; i++)
    {
        if ( x == a[i])
        {
            return true;
        }
    }
    return false;
}

//so lan xuat hien cua mot bien
int solaxuathien(int arr[], int n)
{
    int xx;
    printf("\nNhap vao so ban muon tim: ");
    scanf("%d",&xx);
    int solanxuathien = 0;
    for (int i = 0; i < n; i++)
    {
        if (xx == arr[i])
        {
            solanxuathien +=1;
        }
    }
    printf("so lan xuat hien cua %d la: %d lan",xx,solanxuathien);
}

//nhap
void Nhap(int a[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

//xuat
void xuat(int a[], int n)
{
    for ( int i = 0; i< n ; i++)
    {
        printf("%d \t", a[i]);
    }
}

int main()
{
    int a[100];
    int n,x;
    x=12;

    do 
    {
        printf("Nhap so phan tu cua mang: ");
        scanf("%d", &n);
        if (n<1 || n>100)
        {
            printf("Nhap lai: ");
        }
    }while(n<1 || n>100);

    Nhap(a,n);
    printf("\nCac phan tu trong mang la: \n");
    xuat(a,n);
    Timkiem(a,n,x);
    solaxuathien(a,n);

    getch();
    return 0;
}