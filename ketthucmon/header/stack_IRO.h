#ifndef STACK_IRO_H
#define STACK_IRO_H

#include "stack.h"
#include "Read_Write.h"
#include "stack_getdata.h"
#include "Input.h"
#include "stack_write.h"


int soluong(){
    int size;
    printf("So Luong: ");
    scanf("%d", &size);
    return size;
}


bool kiemtra_ma(STACK s, char ma[]){
    for (int i = 0; i < s.topcb; i++){
        if (strcmp(ma, s.data[i].maCB) == 0)
            return true;
    }
    return false;
}

// nhập từng chuyến bay
CB nhap(STACK s){
    CB cb;
    while (1){
        // nhap mã
        getchar();
        printf("Ma: ");
        fgets(cb.maCB, 10, stdin);
        cb.maCB[strlen(cb.maCB) - 1] = '\0';

        // kiểm tra mã 
        if (kiemtra_ma(s, cb.maCB)){
            system("cls");
            printf("\n\tMa da ton tai!\n");
            continue;
        }

        // khởi tạo ghế 
        Chair_create(cb.maCB);
        //----------------------------hãng
        printf("Hang: ");
        fgets(cb.hang,sizeof(cb.hang),stdin);
        cb.hang[strlen(cb.hang) - 1] = '\0';
        //----------------------------từ đâu
        printf("Tu: ");
        fgets(cb.tu,sizeof(cb.tu),stdin);
        cb.tu[strlen(cb.tu) - 1] = '\0';
        //----------------------------đến đâu
        printf("Den: ");
        fgets(cb.den,sizeof(cb.den),stdin);
        cb.den[strlen(cb.den) - 1] = '\0';
        //----------------------------ngày tháng năm bay
        printf("Ngay bay(dd mm yyyy): ");
        scanf("%d %d %d",&cb.ngayBay.tm_mday, &cb.ngayBay.tm_mon, &cb.ngayBay.tm_year);
        //----------------------------giờ bay
        printf("Gio bay(hh mm): ");
        scanf("%d %d",&cb.ngayBay.tm_hour, &cb.ngayBay.tm_min);
        //----------------------------thời gian bay
        tinh(cb.ngayDen.tm_mday, cb.ngayDen.tm_mon, cb.ngayDen.tm_year, cb.ngayDen.tm_hour, cb.ngayDen.tm_min, cb.ngayBay.tm_mday, cb.ngayBay.tm_mon, cb.ngayBay.tm_year, cb.ngayBay.tm_hour, cb.ngayBay.tm_min);
        //-----------------------------------------------------------------
        printf("Ngay Den: %d/%d/%d\n", cb.ngayDen.tm_mday, cb.ngayDen.tm_mon, cb.ngayDen.tm_year);
        printf("Gio Den: %d:%d\n", cb.ngayDen.tm_hour, cb.ngayDen.tm_min);
        //----------------------------giá vé hạng thương gia
        printf("Gia ve hang 'Thuong Gia': ");
        scanf("%d", &cb.giaCBtg);
        //----------------------------giá vé hạng phổ thông
        printf("Gia ve hang 'Pho Thong': ");
        scanf("%d", &cb.giaCBpth);
        //----------------------------tổng tiền của chuyến bay
        cb.sum = 0;
        return cb;
    }
}


void nhap_cb(){
    // khởi tạo biến
    STACK s;
    CB cb;

    lay_ttcb_day_vao_stack(s);
    int size = soluong();
    for (int i = 0; i < size; i++){
        system("cls");
        printf("\t\tChuyen Bay thu %d\n", i+1);
        cb = nhap(s);
        system("cls");
        Push(s, cb);// đẩy vào stack
    }

    // ghi vao file
    ghi_vao_file(s, s.topcb);
}

// đổi vị trí
void doivitri(CB *a, CB *b){
    CB temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm so sánh thời gian
bool sosanh(const tm &t1, const tm &t2) {
    if (t1.tm_year != t2.tm_year) return t1.tm_year < t2.tm_year;
    if (t1.tm_mon != t2.tm_mon) return t1.tm_mon < t2.tm_mon;
    if (t1.tm_mday != t2.tm_mday) return t1.tm_mday < t2.tm_mday;
    if (t1.tm_hour != t2.tm_hour) return t1.tm_hour < t2.tm_hour;
    return t1.tm_min < t2.tm_min; // So sánh phút cuối cùng
}

// sắp xếp theo thời gian
void sapxep(STACK &s) {
    for (int i = 0; i < s.topcb - 1; i++) {
        for (int j = 0; j < s.topcb - 1 - i; j++) {
            if (!sosanh(s.data[j].ngayBay, s.data[j + 1].ngayBay)) { // Đổi thành so sánh ngược
                doivitri(&s.data[j], &s.data[j + 1]);
            }
        }
    }
}


void xuat_cb(STACK s){
    printf("===============================================================DANH SACH CHUYEN BAY=======================================================================\n");
    printf(" %-7s | %-16s | %-10s | %-10s | %-11s | %-7s | %-11s | %-7s | %-10s | %-10s | %-10s | %-12s\n",
    "Ma", "Hang", "Tu", "Den", "Ngay di", "Gio Di", "Ngay den", "Gio Den", "Thuong Gia", "Pho Thong", "Tong Tien", "Ghe Con Lai");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    //----------------------------------
    for (int i = 0; i < s.topcb; i++){
        display_cb(s.data[i]);
        tinhsoghe(s.data[i].maCB);
    }
}


void Remove(){
    STACK s;
    lay_ttcb_day_vao_stack(s);
    Pop(s);
    ghi_vao_file(s, s.topcb);
}


void timkiem(char tu[], char den[], int ngay, int thang, int nam){
    STACK s;
    int check = 0;
    lay_ttcb_day_vao_stack(s);

    // mở file
    FILE * file = fopen("data/chuyen_bay/TEMP_flight.txt","w");
    // kiểm tra mở file
    kiemtra_mo_file(file);

    // tìm kiếm
    for (int i = 0; i < s.topcb; i++){
        if (strcmp(tu, s.data[i].tu) == 0 && strcmp(den, s.data[i].den) == 0){
            if (s.data[i].ngayBay.tm_year == nam){
                if (s.data[i].ngayBay.tm_mon == thang){
                    if (s.data[i].ngayBay.tm_mday == ngay){
                        write_cb(file, s.data[i]);// ghi cb vào file
                        check = 1;
                    }
                }
            }
        }
    }
    if (check = 0){ printf("\n\tKhong co chuyen bay phu hop!\n"); }

    // đóng file
    fclose(file);
}
#endif//STACK_IRO_H