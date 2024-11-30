#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Câu 1
/// @brief kiem tra so co chia het cho 5 va 6 hay khong
void vonglapvadieukien()
{
    int n;
    printf("nhap vao so nguyen n:");
    scanf("%d", &n);

    int chiahetcho5 = 0;
    int chiahetcho6 = 0;
    //kiem tra n la so nguyen duong hay so nguyen am
    if (n > 0)//nếu n là số nguyên dương
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", i);
            (i % 5 == 0) ? chiahetcho5++ : (i % 6 == 0) ? chiahetcho6++ : 0;
        }
        printf("\n");
    }
    else
    {
        for (int i = n; i <= 1; i--)
        {
            printf("%d ", i);
            (i % 5 == 0) ? chiahetcho5++ : (i % 6 == 0) ? chiahetcho6++ : 0;
        }
        printf("\n");
    }
    printf("so luong so chia het cho 5 la: %d\n", chiahetcho5);
    printf("so luong so chia het cho 6 la: %d\n", chiahetcho6);
    printf("---------------------------------------------------\n");
}

//Câu 2
/// @brief tinh trung binh cong cua so chan trong mang
void ham()
{
    int size;
    int sum = 0;
    int avg = 0;
    int dem = 0;
    printf("nhap vao kich thuoc cua mang:");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("nhap vao phan tu thu %d:", i);
        scanf("%d", &arr[i]);

        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
            dem++;
        }
    }
    avg = sum / dem;
    printf("trung binh cong cac so chan trong mang la: %d", avg);
    printf("\n---------------------------------------------------\n");
}

//Câu 3
/// @brief sap xep mang theo thu tu tang dan
void mang()
{
    int luu;
    int size;
    printf("nhap vao kich thuoc cua mang:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    //nhap vao mang
    for (int i = 0; i < size; i++)
    {
        printf("nhap vao phan tu thu %d:", i + 1);
        scanf("%d", &arr[i]);
    }

    //in ra mang vua nhap
    printf("mang vua nhap la: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //sap xep mang
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                luu = arr[i];
                arr[i] = arr[j];
                arr[j] = luu;
            }
        }
    }

    //in ra mang sau khi sap xep
    printf("mang sau khi sap xep la: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n---------------------------------------------------\n");
}

//Câu 4
/// @brief nhap vao mon hoc va tim vi tri cua mon hoc trong mang
void mangChuoi()
{
    int size ;
    do
    {
        printf("nhap vao so luong mon hoc:");
        scanf("%d", &size);
    } while (size > 10);

    getchar();

    char *monhoc = (char *)malloc(size * 50 * sizeof(char));
    //nhap vao ten mon hoc
    for (int i = 0; i < size; i++)
    {
        printf("nhap vao mon hoc thu %d:", i + 1);
        fgets(monhoc[i], 50, stdin);
    }

    //nhap vao mon hoc can tim
    char monhoccanTim[50];
    printf("nhap vao mon hoc can tim:");
    fgets(monhoccanTim, 50, stdin);

    //in ra vi tri cua mon hoc 
    int dem = 0;
    for (int i = 0; i < size; i++)
    {
        if (strstr(monhoc[i], monhoccanTim))
        {
            printf("mon hoc can tim o vi tri: %d", i + 1);
            dem++;
        }
    }
    if (dem == 0)
    {
        printf("khong tim thay");
    }
    printf("\n---------------------------------------------------\n");
}

void main()
{
    int choice;
    //tao menu
    do
    {
        printf("hay chon chuc nang:\n");
        printf("\t1. kiem tra so co chia het cho 5 va 6 hay khong\n");
        printf("\t2. tinh trung binh cong cua so chan trong mang\n");
        printf("\t3. sap xep mang theo thu tu tang dan\n");
        printf("\t4. tim vi tri cua mon hoc trong mang\n");
        printf("\t5. thoat\n");
        printf("lua chon cua ban la:");
        scanf("%d", &choice);
        //xet tung lua chon
        (choice == 1) ? vonglapvadieukien() : (choice == 2) ? ham() : (choice == 3) ? mang() : (choice == 4) ? mangChuoi() : printf("lua chon khong ton tai");
    } while (choice != 5);
}