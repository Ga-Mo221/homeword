#ifndef STACK_GETDATA_H
#define STACK_GETDATA_H

#include "stack.h"
#include "Position.h"
#include "Read_Write.h"
#include "Filtering.h"


// kiểm tra file mở có thành công không
void kiemtra_mo_file(FILE * file){
    if (file == NULL){
        printf("error!");
        exit(1);
    }
}


bool kiemtra_null(){
    int index = gettopcb();
    if (index == 0){
        printf("Khong co chuyen bay nao");
        return false;
    }
    return true;
}


// lấy thông tin chuyến bay cho vào stack
void lay_ttcb_day_vao_stack(STACK &s){
    
    // khởi tạo biến
    CB cb;
    int i = 0;

    // kiểm tra có chuyến bay nào không
    if (!kiemtra_null()){
        return;
    }

    // mở file
    FILE * file = fopen("data/chuyen_bay/flight.txt", "r");

    // kiểm tra
    kiemtra_mo_file(file);

    // đẩy dữ liệu vào stack
    char line[150];
    while (fgets(line, 150, file) != NULL){
        cb = read_cb(line);
        s.data[i++] = cb; 
    }
    
    Init(&s.topcb, i);// sử dụng hàm khởi tạo

    // đóng file
    fclose(file);
}


#endif//STACK_GETDATA_H