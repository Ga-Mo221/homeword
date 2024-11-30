#include <stdio.h>

int main()
{
    int a, b;
    printf("Nhap vao a, b : ");
    // b phai khac 0
    scanf("%d %d", &a, &b);

    //phep +
    int sum = a + b;
    printf("\n%d + %d = %d", a, b, sum);

    //phep -
    int sub = a - b;
    printf("\n%d - %d = %d", a, b, sub);

    //phep *
    int mul = a * b;
    printf("\n%d * %d = %d", a, b, mul);

    //phep /
    float div = a / (float)b;
    //float div = a / b * 1.0;
    //float div = (float)a / b;
    //float div = (float)(a / b);
    printf("\n%d / %d = %f", a, b, div);

    //phep %
    int mod = a % b;
    printf("\n%d %% %d = %d", a, b, mod);

    return 0;
}
