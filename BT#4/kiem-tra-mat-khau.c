#include <stdio.h>
#include <conio.h>


int main() {
    const int pass = 12345;
    int mat_khau;
    int solan = 1;
    printf("Nhap mat khau: ");
    scanf("%d", &mat_khau);
    do {
        // kiem tra mat khau
        if (mat_khau != pass) {
            printf("Ban da dang nhap that bai lan %d\n", solan);
            printf("Nhap lai mat khau: ");
            scanf("%d", &mat_khau);
            solan++;
        }
        else
        {
            printf("Ban da dang nhap thanh cong");
            break;
        }
    } while (mat_khau != pass && solan <= 3);
    return 0;
}