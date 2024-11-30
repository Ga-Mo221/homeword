#include <stdio.h>

// Ham tinh tong
void tinhTong(float n, float m) {
    float tong = n + m;
    printf("\nTong cua %.1f va %.1f la %.1f\n", n, m, tong);
}

// Ham tinh hieu
void tinhHieu(float n, float m) {
    float hieu = n - m;
    printf("\nHieu cua %.1f va %.1f la %.1f\n", n, m, hieu);
}

// Ham tinh tich
void tinhTich(float n, float m) {
    float tich = n * m;
    printf("\nTich cua %.1f va %.1f la %.1f\n", n, m, tich);
}

// Ham tinh thuong
void tinhThuong(float n, float m) {
    float thuong = 0;
    if (m != 0) {
        thuong = n / m;
        printf("\nThuong cua %.1f va %.1f la %.1f\n", n, m, thuong);
    } else {
        printf("\nKhong thuc hien duoc phep chia cho 0\n");
    }
}

// Ham main
int main() {
    char option;
    float n, m;

    printf("Nhap n = "); scanf("%f", &n);
    printf("Nhap m = "); scanf("%f", &m);

    do {
        // Tao menu
        printf("\nNhan + de thuc hien phep tinh tong");
        printf("\nNhan - de thuc hien phep tinh hieu");
        printf("\nNhan * de thuc hien phep tinh tich");
        printf("\nNhan / de thuc hien phep tinh thuong");
        printf("\nNhap e de thoat chuong trinh\n");
        printf("\nNhap phep tinh: ");
        fflush(stdin);
        scanf(" %c", &option);


        switch(option) {
            case '+':
                tinhTong(n, m);
                break;
            case '-':
                tinhHieu(n, m);
                break;
            case '*':
                tinhTich(n, m);
                break;
            case '/':
                tinhThuong(n, m);
                break;
            case 'e':
                break;
            default:
                printf("Khong co tinh nang nay");
        }
    } while(option != 'e');

    return 0;
}