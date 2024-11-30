#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Sinhvien
{
    int MaSinhVien;
    char TenSinhVien[25];
    float DiemSinhVien;
};

//Khai bao kieu du lieu Sinhvien
typedef struct Sinhvien SV;

void nhap(SV arr_sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap ma sinh vien: ");
        scanf(" %d", &arr_sv[i].MaSinhVien);
        getchar();
        printf("Nhap ten sinh vien: ");
        fgets(arr_sv[i].TenSinhVien, 25, stdin);
        arr_sv[i].TenSinhVien[strlen(arr_sv[i].TenSinhVien) - 1] = '\0';
        printf("Nhap diem sinh vien: ");
        scanf("%f", &arr_sv[i].DiemSinhVien);
    }
}

void xuat(SV arr_sv[], int n)
{
    printf("\nDANH SACH SINH VIEN:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%3d\t%25s\t%3.2f\n", arr_sv[i].MaSinhVien, arr_sv[i].TenSinhVien, arr_sv[i].DiemSinhVien);
    }
}

int main()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SV *arr_sv = (SV*)malloc(n * sizeof(SV));
    nhap(arr_sv, n);
    xuat(arr_sv, n);
    free(arr_sv);
    return 0;
}