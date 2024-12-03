#ifndef POSITION_H
#define POSITION_H


// lấy vị trí top chuyến bay
int gettopcb(){
    // khởi tạo biến
    int top; 

    // mở file
    FILE *ft = fopen("data/chuyen_bay/Topcb.txt", "r");

    // kiểm tra
    if (ft == NULL){
        printf("error: Topvb.txt\n");
        return 0;
    }
    
    // lấy giá trị
    char linet[10];
    while (fgets(linet, 10, ft) != NULL){
        sscanf(linet, "%d", &top);
    }

    // đóng file
    fclose(ft);
    return top;
}

// lấy vị trí top vé
int gettopve(){
    // khởi tạo biến
    int top;

    // mở file
    FILE *ft = fopen("data/ve/Topve.txt", "r");

    // kiểm tra
    if (ft == NULL){
        printf("error: Topve.txt\n");
        return 0;
    }

    // lấy giá trị
    char linet[10];
    while (fgets(linet, 10, ft) != NULL){
        sscanf(linet, "%d", &top);
    }

    // đóng file
    fclose(ft);
    return top;
}

// ghi vị trí vào file chuyến bay
void luutopcb(int topc){
    // mở file
    FILE * ft = fopen("data/chuyen_bay/Topcb.txt", "w");
    
    // kiểm tra
    if (ft == NULL){
        printf("error: Topvb.txt\n");
        exit(1);
    }

    // ghi
    fprintf(ft, "%d\n", topc);

    // đóng file
    fclose(ft);
}

// ghi vị trí vào file vé
void luutopve(int topv){
    // mở file
    FILE *ft = fopen("data/ve/Topve.txt", "w");
    printf("1\n");
    // kiểm tra
    if (ft == NULL){
        printf("error: Topve.txt\n");
        exit(1);
    }
    printf("mo file ve thanh cong\n");
    // ghi
    fprintf(ft, "%d\n", topv);
    printf("2\n");
    // đóng file
    fclose(ft);
}

#endif//PISITION