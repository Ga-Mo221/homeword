#include <stdio.h>
#include <conio.h>

int arr[8];
int kiemTraBoiSo()
{
    int dem = 0;
    for (int i = 0; i < 8 ; i++)
    {
        if (arr[i] % 6 == 0)
        {
            dem++;
            printf("so chia het cho 6 trong mang la: %d\n",arr[i]);
        }
    }
    if ( dem == 0)
    {
        printf("\ntrong mang khong co so chia het cho 6\n");
    }
    return 0;
}

int sumBoiSo_6()
{
    int dem = 0;
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] % 6 == 0)
        {
            dem = dem + arr[i];
        }
    }
    printf("\ntong cac so chia het cho 6 la: %d",dem);
    return 0;
}

int main()
{
    int i, option;
    printf("nhap vao 8 pahn tu trong mang: ");
    for (i = 0; i < 8; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("phan tu trong mang\n");
    for (i = 0; i < 8; i++)
    {
        printf("%5d", arr[i]);
    }
    while(i)
    {
        printf("\n 1_Kiem tra boi so 6");
        printf("\n 2_Sum boi so 6\n");
        printf(" 3_Thoat");
        printf("\n moi ban lua chon chuc nang");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
            {
                kiemTraBoiSo();
                break;
            }
            case 2:
            {
                sumBoiSo_6();
                break;
            }
            case 3:
            {
                printf("xin cam on");
                return 0;
                break;
            }
        }
    }
    return 0;
}