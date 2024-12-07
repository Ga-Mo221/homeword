#ifndef STACK_WRITE_H
#define STACK_WRITE_H

#include "Ql_struct.h"
#include "stack.h"
#include "stack_getdata.h"
#include "Read_Write.h"


void ghi_vao_file(STACK s, int top){
    FILE * file = fopen("data/chuyen_bay/flight.txt", "w");

    // kiểm tra file
    kiemtra_mo_file(file);

    for (int i = 0; i < top; i++){
        write_cb(file, s.data[i]);
    }
    luutopcb(s.topcb);
    printf("ghi thanh cong!\n");
    
    // đóng file
    fclose(file);
}
#endif//STACK_WRITE_H