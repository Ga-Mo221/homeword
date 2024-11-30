#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "Hello VTC";
    char dest[] = "welcome";
    char kq[30];
    strcpy(dest,src);
    printf("ket qua sau khi copy: %s\n", dest);
    return 0;
}