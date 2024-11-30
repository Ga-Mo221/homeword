#include <stdio.h>

int main() {
    // 1 = breakfast, 2 = lunch, 3 = dinner
    int a;
    printf("Please input your choice ( 1 = breakfast , 2 = lunch, 3 = dinner )\n");
    scanf("%d", &a);
    printf("%d\n", a);
    
    if (a == 1) {
        printf("I prepare bread\n");
        printf("I set the table\n");
        printf("I wash the dishes\n");
    } else if (a == 2) {
        printf("I go to the restaurant\n");
    } else if (a == 3) {
        printf("I cook rice\n");
        printf("I set the table\n");
        printf("I wash the dishes\n");
    } else {
        printf("Nothing I do\n");
    }
    return 0;
}