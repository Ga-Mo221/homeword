#include <stdio.h>

int main()
{
    int a ;
    printf("Nhap vao so nguyen a : ");
    scanf("%d", &a);

    switch (a)
    {
        case 1:
            printf("Mot");
            break;
        case 2:
            printf("Hai");
            break;
        case 3:
            printf("Ba");
            break;
        case 4:
            printf("Bon");
            break;
        case 5:
            printf("Nam");
            break;
        default:
            printf("Khong hop le");
            break;
    }
}
