#include <stdio.h>
#include <conio.h>
int so1, so2;
float thuong;
char pheptoan;

void nhap_vao_so()
{
    printf("Nhap vao hai so nguyen : ");
    scanf("%d%d",&so1,&so2);
    fflush(stdin);
    printf("\nNhap vao phep toan (+,-,*,/) : ");
    scanf(" %c", &pheptoan);

}

char case1()
{
    return printf("\n%d + %d = %d\n",so1,so2,so1+so2);
}
void case2()
{
    printf("\n%d - %d = %d\n",so1,so2,so1-so2);
}
void case3()
{
    printf("\n%d * %d = %d\n",so1,so2,so1*so2);
}
void case4()
{
    if (so2 != 0)
            {
                thuong = (float)so1/so2;
                printf("\n%d / %d = %.2f\n",so1,so2,thuong);
            }
                else printf("\nkhong chia duoc cho 0\n");
}

int main()
{
    nhap_vao_so();

    switch (pheptoan)
    {
        case '+':
        {
            case1();
            break;
        }
        case '-':
        {
            case2();
            break;
        }
        case '*':
        {
            case3();
            break;
        }
        case '/':
        {
            case4();
            break;
        }
        default: printf("chua ho tro phep toan %c\n",pheptoan);
        break;
    }
    getch();
    return 0;
}
