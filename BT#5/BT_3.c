#include <stdio.h>
// Khai bao hang so
#define PI 3.14

// Ham tinh chu vi
float tinhChuVi(int bk) 
{
    float CV = 2*PI*bk;
    return printf("Chu vi của hình tròn là %1.2f \n", CV);
}

// Ham tinh dien tich
float tinhDienTich(int bk) 
{
    float DT = PI*bk*bk;
    return printf("dien tich hinh tron la %1.2f", DT);
}

// Ham main de chay chuong trinh
int main() {
    // Khai bao bien ban kinh
    int r;
    // Nhap ban kinh
    printf("Nhap ban kinh r = "); scanf("%d", &r);
    // Goi ham tinh chu vi
    tinhChuVi(r);
    // Goi ham tinh dien tich
    tinhDienTich(r);
}