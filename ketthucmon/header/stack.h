#ifndef STACK_H
#define STACK_H
#define MAX 100
#include "Ql_struct.h"
#include "Position.h"

struct stack{
    int topcb;
    CB data[MAX];
};
typedef struct stack STACK;


void Init(int *a, int index){
    *a = index;
}


int Empty(STACK s){
    return(s.topcb == 0);
}


int Isfull(STACK s){
    return(s.topcb == MAX);
}


void Push(STACK &s, CB cb){
    if(!Isfull(s)){
        s.data[s.topcb++] = cb;
    }else{ printf("errol\n"); }
}


void Pop(STACK &s){
    if(!Empty(s)){
        s.topcb--;
    }
}

#endif 
