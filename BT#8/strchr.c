#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "chao ung ban den voi VTC academy ";
    char ch = 'm';
    if (strchr(str, ch))
    {
        printf("ky tu %c co xuat hien trong chuoi \n", ch);
    }
    else
    {
        printf("ky tu %c khong xuat hien trong chuoi ", ch);
    }
}