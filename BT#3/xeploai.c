#include <stdio.h>

int main(){
    float toan, ly, diemTB;
    printf("Nhap vao diem toan : ");
    scanf("%f", &toan);
    printf("Nhap vao diem ly : ");
    scanf("%f", &ly);

    // xet dieu kien nhap diem co loi hay khong
    if (toan >= 0 && toan <= 10 && ly >= 0 && ly <= 10)
    {
        diemTB = (toan + ly) / 2;
        printf("Diem trung binh la : %.2f\n", diemTB);

        switch ((int)diemTB)
        {
            case 10:
            case 9:
                printf("Xep loai : Xuat sac\n");
                break;
            case 8:
                printf("Xep loai : Gioi\n");
                break;
            case 7:
                printf("Xep loai : Kha\n");
                break;
            case 6:
            case 5:
                printf("Xep loai : Trung binh\n");
             break;
            default:
                printf("Xep loai : Yeu\n");
                break;
        }
    }
    else
    {
        if (toan < 0 || toan > 10)
        {
            printf("Diem toan khong hop le\n");
        }
        if (ly < 0 || ly > 10)
        {
            printf("Diem ly khong hop le\n");
        }
    }
}
