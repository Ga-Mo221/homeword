#include <stdio.h>
#include <string.h>

struct NhanVien
{
    int maNV;
    char hoTen[25];
    int tuoi;
    char gioiTinh[10];
    float luongCB;
    int soNgayLam;
};

typedef struct NhanVien NV[2];

void nhapThongTin(NV nv)
{
    printf("---NHAP THONG TIN NHAN VIEN---\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Nhan Vien Thu %d: \n", i + 1);
        printf("Ma: ");
        scanf("%d", &nv[i].maNV);
        getchar();
        printf("Ten: ");
        fgets(nv[i].hoTen, 25, stdin);
        nv[i].hoTen[strlen(nv[i].hoTen) - 1] = '\0';
        printf("Tuoi: ");
        scanf("%d", &nv[i].tuoi);
        getchar();
        printf("Gioi tinh: ");
        fgets(nv[i].gioiTinh, 10, stdin);
        nv[i].gioiTinh[strlen(nv[i].gioiTinh) - 1] = '\0';
        printf("Luong co ban: ");
        scanf("%f", &nv[i].luongCB);
        printf("So ngay lam: ");
        scanf("%d", &nv[i].soNgayLam);
        printf("-----------------------------------\n");
    }
}

float luongThang(NV nv, int i)
{
    return nv[i].luongCB * nv[i].soNgayLam;
}

void xuat(NV nv)
{
    printf("\n---DANH SACH NHAN VIEN---\n");
    printf(" %-5s| %-20s| %-5s| %-10s| %-20s| %-10s| %-25s|\n", "Ma", "Ho Ten", "Tuoi", "Gioi Tinh", "Luong Co Ban", "So Ngay Lam", "Luong Thang");
    for (int i = 0; i < 2; i++)
    {
        float luong = luongThang(nv, i);
        printf(" %-5d| %-20s| %-5d| %-10s| %-20.2f| %-11d| %-25.2f|\n", nv[i].maNV, nv[i].hoTen, nv[i].tuoi, nv[i].gioiTinh, nv[i].luongCB, nv[i].soNgayLam, luong);
    }
}

void timKiem(NV nv)
{
    printf("\n---TIM KIEM NHAN VIEN---\n");
    printf("Nhap ten nhan vien can tim: ");
    getchar();
    char ten[25];
    fgets(ten, 25, stdin);
    ten[strlen(ten) - 1] = '\0';
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(ten, nv[i].hoTen) == 0)
        {
            printf("Co nhan vien %s trong danh sach\n", ten);
            return;
        }
    }
    printf("Khong tim thay nhan vien %s trong danh sach\n", ten);
}

int main()
{
    NV nv;
    nhapThongTin(nv);
    xuat(nv);
    timKiem(nv);
    return 0;
}