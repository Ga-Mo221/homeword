#include <stdio.h>
#include <conio.h>

char case1()
    {
        return printf("Xin chao cac ban\n");
    }

int case2()
    {
        int c;
        printf("Ban da chon chuc nang doi do C sang do F\n");
        printf("\tHay nhap vao do C : ");
        scanf("%d", &c);
        int f = c * 1.8 + 32;
        printf("\tDo F la : %d\n", f);
    }

int case3()
    {
        int r;
        const float PI = 3.14;
        printf("Ban da chon chuc nang tinh chu vi va dien tich hinh tron\n");
        printf("\tHay nhap vao ban kinh hinh tron : ");
        scanf("%d", &r);
        float cv = 2 * PI * r;
    }

int main()
{
    int choose;
    printf("Chon 1 trong 3 lua chon sau : \n");
    printf("\t1.In ra man hinh xin chao cac ban\n");
    printf("\t2.Chuc nang doi do C sang do F\n");
    printf("\t3.Chuc nang tinh chu vi va dien tich hinh tron\n");

    printf("Nhap vao lua chon cua ban : ");
    scanf("%d", &choose);

    switch (choose)
    {
        case 1:
        {
            case1();
            break;
        }
        case 2:
        {
            case2();
            break;
        }
        case 3:
        {
            case3();
            break;
        }
        default:printf("Lua chon khong hop le\n");
        break;
    }
    getch();
}
