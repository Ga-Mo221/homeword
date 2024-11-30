#include <stdio.h>
#include <string.h>

int main()
{
    char str1[30] = "you are ";
    char str2[200] = "cute in the world ";
    strncat(str1,str2,4);
    printf("%s", str1);
    return 0;
}