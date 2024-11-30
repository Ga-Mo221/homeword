#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


// hang so
#define max 100


// struct
struct date{
    int ngay, thang, nam;
}; typedef date D;


struct HangHoa{
    char id[10];
    char ten[100];
    D ngayxuat;
    int gia;
}; typedef HangHoa HH;


struct Queue{
    HH data[max];
    int rear;
    int front;
}; typedef Queue Q;


// ham khoi tao
void Init(Q &q){
    q.front = 0;
    q.rear = 0;
}


// ham start
void start(){
    system("cls");
}


// ham end
void end(){
    printf("\n\tbam phim bat ki de thoat...\n");
    getch();
    system("cls");
}


// ham kiem tra rong
int Empty(Q q){
    return (q.rear == 0);
}


// ham kiem tra day
int full(Q q){
    return (q.rear == max);
}


// ham day gia tri vao
void Push(Q &q, HH h){
    if (!full(q)){
        q.data[q.rear++] = h;
    }else { printf("errol: full!\n"); }
}


// ham xoa gia tri dau
void Remove(Q &q, Q &qdbx){
    HH h;
    if (!Empty(q)){
        h = q.data[q.front];
        for (int i = q.front; i < q.rear-1; i++){
            q.data[i] = q.data[i+1];
        }
        q.rear--;
    }else { printf("errol: empty!\n"); }

    qdbx.data[qdbx.rear++] = h;
}


// ham nhap gia tri hang hoa
void input(Q &q){
    //khai bao bien
    int size;
    HH h;
    int sizerear;

    printf("so luong: ");
    scanf("%d", &size);
    sizerear = q.rear;

    for (int i = sizerear; i < sizerear+size; i++){
        getchar();

        printf("id   : "); 
        fgets(h.id, sizeof(h.id), stdin);
        h.id[strlen(h.id) - 1] = '\0';   

        printf("ten  : ");
        fgets(h.ten, sizeof(h.ten), stdin);
        h.ten[strlen(h.ten) - 1] = '\0';   

        printf("ngay : ");
        scanf("%d/%d/%d", &h.ngayxuat.ngay, &h.ngayxuat.thang, &h.ngayxuat.nam);

        printf("gia  : ");
        scanf("%d", &h.gia);

        Push(q, h);// day gia tri vao data   
    }
}


// ham xuat
void output(Q q){
    if (!Empty(q)){
        for (int j = q.front; j < q.rear; j++){
            printf("%s | %s | %d/%d/%d | %d\n", q.data[j].id, q.data[j].ten, q.data[j].ngayxuat.ngay, q.data[j].ngayxuat.thang, q.data[j].ngayxuat.nam, q.data[j].gia);
        }
    }else {printf("\terrol: empty!\n\n"); }
}


// tim kiem cac san phan theo ma
void xuatdonhangtheoid(Q q){
    // khoi tao bien
    char id[10];

    if (!Empty(q)){
        printf("nhap id: ");
        fgets(id, sizeof(id), stdin);
        id[strlen(id) - 1] = '\0';

        for (int i = q.front; i < q.rear; i++){
            if (strcmp(id, q.data[i].id) == 0){
                printf("%s | %s | %d/%d/%d | %d\n", q.data[i].id, q.data[i].ten, q.data[i].ngayxuat.ngay, q.data[i].ngayxuat.thang, q.data[i].ngayxuat.nam, q.data[i].gia);
            }
        }
    }else { printf("\terrol: empty!\n\n"); }// kiem tra id co ton tai khong
}


// xuat san pham da boc xep
void hanghoadabocxep(Q qdbx){
    if (!Empty(qdbx)){
        for (int i = qdbx.front; i < qdbx.rear; i++){
            printf("%s | %s | %d/%d/%d | %d\n", qdbx.data[i].id, qdbx.data[i].ten, qdbx.data[i].ngayxuat.ngay, qdbx.data[i].ngayxuat.thang, qdbx.data[i].ngayxuat.nam, qdbx.data[i].gia);
    }
    }else{ printf("\terrol: empty!\n\n"); }
}


// ham main
int main(){
    // khoi tao bien
    int choice;
    Q q;
    Q qdbx;


    //goi ham khoi tao
    Init(q);
    Init(qdbx);


    do{
        printf("\t1. nhap vao\n");
        printf("\t2. xoa\n");
        printf("\t3. cac don hang theo ma\n");
        printf("\t4. cac don hang chua boc xep\n");
        printf("\t5. cac don hang da boc xep\n");
        printf("\t6. thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:{
                start();
                input(q);
                end();
                break;
            }
            case 2:{
                start();
                Remove(q, qdbx);
                end();
                break;
            }
            case 3:{
                start();
                xuatdonhangtheoid(q);
                end();
                break;
            }
            case 4:{
                start();
                printf("front: %d | rear: %d\n",qdbx.front, qdbx.rear);
                output(q);
                end();
                break;
            }
            case 5:{
                start();
                printf("front: %d | rear: %d\n",qdbx.front, qdbx.rear);
                hanghoadabocxep(qdbx);
                end();
                break;
            }
            case 6: end(); break;
        }
    }while(choice != 6);
    return 0;
}