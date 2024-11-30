#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


#define max 100 // hang so


struct Maytinh{
    char id[6];
    char ten[256];
    struct tm date;
    float giaxuat;
};


typedef Maytinh MT;


struct Stack{
    int top;
    MT data[max];
};



typedef Stack S;


//code
void Init(S &s){
    s.top = 0;
}


int Empty(S s){
    return (s.top == 0);
}


int Isfull(S s){
    return (s.top == max);
}


void Push(S &s, MT mt, int x){
    if (!Isfull(s)){
        s.data[x] = mt;
        s.top++;
    }else{printf("errol: full\n");}
}


void Pop(S &s){
    if (!Empty(s)){
        s.top--;
        if (s.top < 0) s.top = 0;
    }else{printf("errol: Empty\n");}
}


void input(S &s){
    int x;
    MT mt;
    scanf("%d", &x);
    int X = s.top + x;
    for (int i = s.top; i < X; i++){
        getchar();
        fgets(mt.id, 6, stdin);
        mt.id[strlen(mt.id) - 1] = '\0';
        fgets(mt.ten, 256, stdin);
        mt.ten[strlen(mt.ten) - 1] = '\0';
        scanf("%d/%d/%d", &mt.date.tm_mday, &mt.date.tm_mon, &mt.date.tm_year);
        scanf("%f", &mt.giaxuat);
        Push(s, mt, i);
    }
}


void output(S s){
    printf("DANH SACH MAY TINH\n");
    for (int i = s.top-1; i >= 0; i--){
        printf("ma: %-6s | ten: %-17s | ngay: %2d/%2d/%-6d | gia: %-10.2f\n", 
        s.data[i].id, s.data[i].ten, s.data[i].date.tm_mday, s.data[i].date.tm_mon, s.data[i].date.tm_year, s.data[i].giaxuat);
    }
}


void kiemtra(S s){
    getchar();
    char ma[6];
    printf("nhap ma: ");
    fgets(ma, 6, stdin);
    ma[strlen(ma) - 1] = '\0';
    int check = 0;


    for (int i = 0; i < s.top; i++){
        if (strcmp(s.data[i].id, ma) == 0) check = 1;
    }


    if (check) printf("co\n");
    else printf("khong co\n");
}


//main
int main(){
    S s;
    MT mt;


    int choice;
    Init(s);


    do{
        printf("\t1.them\n");
        printf("\t2.xuat\n");
        printf("\t3.xoa\n");
        printf("\t4.kiem tra\n");
        printf("\t5.thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        system("cls");


        switch (choice){
            case 1:{
                input(s);
                printf("\nbam phim bat ki de thoat...\n");
                getch();
                system("cls");
                break;
            }
            case 2:{
                output(s);
                printf("\nbam phim bat ki de thoat...\n");
                getch();
                system("cls");
                break;
            }
            case 3:{
                Pop(s);
                printf("xoa thanh cong!\n");
                printf("\nbam phim bat ki de thoat...\n");
                getch();
                system("cls");
                break;
            }
            case 4:{
                kiemtra(s);
                printf("\nbam phim bat ki de thoat...\n");
                getch();
                system("cls");
                break;
            }
            case 5:
                break;
            default:
                break;
        }
    } while (choice != 5);
    
    return 0;
}