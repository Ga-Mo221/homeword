#include <stdio.h>
#include <string.h>

int main()
{
    char lhs[] = "Arms";
    char rhs[] = "Armstrong";
    int result;
    result = strcmp(lhs,rhs);
    if (result != 0)
    {
        if (result > 0)
        {
            printf("chuoi 1 lon hon chuoi 2");
        }
        else
        {
            printf("chuoi 2 lon hon chuoi 1");
        }
    }
    else
    {
        printf("2 chuoi bang nhau");
    }
    return 0;
}