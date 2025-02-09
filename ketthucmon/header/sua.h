#ifndef SUA_H
#define SUA_H

#include "Ql_struct.h"
#include "Read_Write.h"
#include "Filtering.h"
#include "Output.h"
#include "Input.h"

// chọn chuyến bay cần sửa
int sua_cb()
{
    system("cls");
    //khai báo biến
    CB cb;
    char macbsua[10];
    int dem;


    // mở file
    FILE *f = fopen("data/chuyen_bay/flight.txt", "r");
    FILE *f1 = fopen("data/chuyen_bay/TEMP_flight.txt", "w");
    // kiểm tra file có tồn tại không
    if (f == NULL || f1 == NULL)
    {
        printf("File khong ton tai\n");
        exit(1);
    }


    Filtering_flight();
    dem = Output_flight_file(f);
    if (dem == 0)
    {
        system("cls");
        printf("\n\tKHONG CO CHUYEN BAY NAO!!!\n");
        fclose(f);
        fclose(f1);
        remove("data/chuyen_bay/TEMP_flight.txt");
        printf("Bam phim bat ki de thoat...\n");
        getch();
        system("cls");
        return 0;
    }
    // đưa con trỏ về lại đầu file
    rewind(f);


    // Nhập mã chuyến bay cần sửa
    //getchar();
    printf("\n\nNhap ma chuyen bay can sua: ");
    fgets(macbsua, sizeof(macbsua), stdin);
    macbsua[strlen(macbsua) - 1] = '\0';
    system("cls");



    // đọc file
    char linesuacb[150];
    int found = 0;
    while (fgets(linesuacb, sizeof(linesuacb), f) != NULL)
    {
        cb = read_cb(linesuacb);
        if (strcmp(cb.maCB, macbsua) == 0)
        {
            //------------------------tiêu đề-----------------------------
            printf("===============================================================DANH SACH CHUYEN BAY=============================================================\n");
            printf(" %-7s | %-20s | %-10s | %-10s | %-11s | %-7s | %-11s | %-7s | %-10s | %-10s | %-15s\n",
            "Ma", "Hang", "Tu", "Den", "Ngay di", "Gio Di", "Ngay den", "Gio Den", "Thuong Gia", "Pho Thong", "Tong Tien");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");

            // in ra chuyến bay cần sửa
            display_cb(cb);

            // cập nhật thời gian bay
            printf("\n\nNhap ngay bay moi (dd mm yyyy): ");
            scanf("%d %d %d", &cb.ngayBay.tm_mday, &cb.ngayBay.tm_mon, &cb.ngayBay.tm_year);
            printf("Nhap gio bay moi (hh mm): ");
            scanf("%d %d", &cb.ngayBay.tm_hour, &cb.ngayBay.tm_min);
            tinh(cb.ngayDen.tm_mday, cb.ngayDen.tm_mon, cb.ngayDen.tm_year, cb.ngayDen.tm_hour, cb.ngayDen.tm_min, cb.ngayBay.tm_mday, cb.ngayBay.tm_mon, cb.ngayBay.tm_year, cb.ngayBay.tm_hour, cb.ngayBay.tm_min);
            //-----------------------------------------------------------------
            printf("Ngay Den: %d/%d/%d\n", cb.ngayDen.tm_mday, cb.ngayDen.tm_mon, cb.ngayDen.tm_year);
            printf("Gio Den: %d:%d\n", cb.ngayDen.tm_hour, cb.ngayDen.tm_min);

            getch();

            // cập nhật vào file temp
            write_cb(f1, cb);
            found = 1; 
        }
        else
        {
            write_cb(f1, cb);
        }
    }
    if (found == 0)
    {
        printf("Chuyen bay khong ton tai\n");
        getch();
    }
    fclose(f);
    fclose(f1);
    remove("data/chuyen_bay/flight.txt");
    rename("data/chuyen_bay/TEMP_flight.txt", "data/chuyen_bay/flight.txt"); // đổi tên file temp 
    system("cls");
    printf("Thay doi thanh cong ^-^\nBam phim bat ki de thoat...\n");
    getch();
    system("cls");
    return 0;
}

// sửa thông tin hành khách f là profile_user(r), f1 là T_profile_user(w)
void sua_hk(FILE *f, FILE *f1, char idsua[])
{
    // khởi tạo biến
    HK hk;


    // mở file
    if (f == NULL || f1 == NULL)
    {
        printf("File khong ton tai\n");
        getch();
        exit(1);
    }


    char linesuahk[150];
    int found = 0;
    while (fgets(linesuahk, sizeof(linesuahk), f) != NULL)
    {
        hk = read_user(linesuahk);
        if (strcmp(hk.id, idsua) == 0)
        {
            //-----------------------------tiêu đề------------------------------------------
            printf("=======================================DANH SACH HANH KHACH VS KHACH HANG==========================================\n");
            printf(" %-15s | %-20s | %-13s | %-13s | %-13s | %-10s | %-15s\n",
                    "ID", "Ten", "Gioi Tinh", "Quoc Tich", "SDT", "Tuoi", "Ngay Sinh");
            printf("-------------------------------------------------------------------------------------------------------------------\n");


            // in ra hanh khach cần sửa
            display_user(hk);

            printf("\nBan muon sua gi!\n");
            printf("\t1.Ten\n\t2.SDT\n\t3.Ngay Sinh\n\t4.Thoat\n");
            int chon;
            printf("Chon: ");
            scanf("%d", &chon);
            getchar();

            switch (chon)
            {
                case 1:
                {
                    // cập nhật thông tin hanh khach
                    printf("Nhap ten hanh khach: ");
                    fgets(hk.ten, sizeof(hk.ten), stdin);
                    hk.ten[strlen(hk.ten) - 1] = '\0';
                    break;
                }
                case 2:
                {
                    printf("Nhap so dien thoai: ");
                    fgets(hk.sdt, sizeof(hk.sdt), stdin);
                    hk.sdt[strlen(hk.sdt) - 1] = '\0';
                    break;
                }
                case 3:
                {
                    printf("Nhap ngay sinh (dd/mm/yyyy): ");
                    scanf("%d %d %d", &hk.ngaySinh.tm_mday, &hk.ngaySinh.tm_mon, &hk.ngaySinh.tm_year);
                    break;
                }
                case 4:
                    break;
            }
            // cập nhật vào file temp
            write_hk(f1, hk);
            found = 1;
        }
        else
        {
            write_hk(f1, hk);
        }
    }
    
    if (found == 0)
    {
        printf("Hanh khach khong ton tai\n");
    }
    fclose(f);
    fclose(f1);
}

void menu_sua()
{
    int choice;
    do 
    {
        int demcb2;
        system("cls");
        printf("==========================MENU SUA==========================\n");
        printf("\t\t1.Sua chuyen bay\n");
        printf("\t\t2.Sua hanh khach\n");
        printf("\t\t3.Thoat\n");
        printf("chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            sua_cb();
            break;
        case 2:
        {   
            system("cls");
            // xuất danh sách user profile
            FILE *file = fopen("data/hanh_khach/TEMP_profile_user.txt", "r");
            demcb2 = Output_user(file);
            if (demcb2 == 0)
            {
                fclose(file);
                printf("\n\tKHON CO THONG TIN HANH KAHCH NAO!!!\n");
                printf("Bam phim bat ki de thoat...\n");
                getch();
                system("cls");
                break;
            }
            fclose(file);


            // Nhập số cccd cần chỉnh sửa
            char idsua[15];
            printf("Nhap CCCD cua hanh khach can sua: ");
            fgets(idsua, sizeof(idsua), stdin);
            idsua[strlen(idsua) - 1] = '\0';
            system("cls");


            FILE *f = fopen("data/hanh_khach/TEMP_profile_user.txt", "r");
            FILE *f1 = fopen("data/hanh_khach/t_profile_user.txt", "w");
            sua_hk(f, f1, idsua);
            fclose(f);
            fclose(f1);
            remove("data/hanh_khach/TEMP_profile_user.txt");
            rename("data/hanh_khach/t_profile_user.txt","data/hanh_khach/TEMP_profile_user.txt");
            system("cls");
            printf("Thay doi thanh cong ^-^\nBam phim bat ki de thoat...\n");
            getch();
            system("cls");
            break;
        }
        case 3:
            system("cls");
            break;
        default:
            printf("Lua chon khong hop le\n");
            exit(1);
        }
    }while (choice != 3);
}

#endif // SUA_H
