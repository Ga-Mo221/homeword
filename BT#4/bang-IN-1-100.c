#include <stdio.h>

int main() {
    int hang = 1, cot, so = 1;
    // xet hang
    for (;hang <=10; hang++) {
        // xet cot
        for (cot = 1;cot <=10; ) {
            printf("%3d\t", so);
            so+=10;
            cot++;
        }
        so = hang + 1;
        printf("\n");
    }
    printf("-----------------------------------------\n");
    return 0;
}