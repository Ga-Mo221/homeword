#include <stdio.h>
#include <conio.h>

int main()
{
    printf("Hay lua chon cac hinh sau de tinh chu vi va dien tich : \n");
    printf("\t1. Hinh vuong\n\t2.Hinh chu nhat\n\t3.Hinh tron\n");
    int choose;
    printf("\nNhap vao lua chon cua ban (1, 2, 3 ): ");
    scanf("%d", &choose);

    switch (choose)
    {
        case 1:
        {
            int x ;
            printf("Ban da chon hinh vuong\n");
            printf("Nhap vao canh hinh vuong : ");
            scanf("%d", &x);
            printf("Chu vi hinh vuong la : %d\n", x * 4);
            printf("Dien tich hinh vuong la : %d\n", x * x);
            break;
        }
        case 2:
        {
            int a, b;
            printf("Ban da chon hinh chu nhat\n");
            printf("Nhap vao chieu dai hinh chu nhat : ");
            scanf("%d", &a);
            printf("Nhap vao chieu rong hinh chu nhat : ");
            scanf("%d", &b);
            printf("Chu vi hinh chu nhat la : %d\n", (a + b) * 2);
            printf("Dien tich hinh chu nhat la : %d\n", a * b);
            break;
        }
        case 3:
        {
            int r;
            printf("Ban da cho hinh tron\n");
            printf("Nhap vao ban kinh hinh tron : ");
            scanf("%d", &r);
            printf("Chu vi hinh tron la : %f\n", 2 * 3.14 * r);
            printf("Dien tich hinh tron la : %f\n", 3.14 * r * r);
            break;
        }
        default:
        {
            printf("Lua chon khong hop le\n");
        }
    }
    getch();
    return 0;
}
