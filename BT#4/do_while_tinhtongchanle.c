#include <stdio.h>

int main()
{

    int i = 0, sum = 0, sumchan = 0, sumle = 0;
    while(i<=10)
    do{
        sum += i;
        if (i%2 == 0)
        {
            sumchan += i;
        }
        else
        {
            sumle += i;
        }
        i++;
    }while(i<=10);
    printf("sum = %d\n", sum);
    printf("sumchan = %d\n", sumchan);
    printf("sumle = %d\n", sumle);
    return 0;
}
