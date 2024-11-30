#include <stdio.h>
#include <conio.h>

int siZe()
{
    int size;
    printf("nhap vao kich thuoc cua mang: ");
    scanf("%d",&size);
    printf("\n");
    return size;
}

void input(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("List[%d] = ",i);
        scanf("%d",&arr[i]);
    }
}

void nhohon0(int arr[], int size)
{
    int dem = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]< 0)
        {
            dem += 1;
        }
    }
    switch (dem)
    {
    case 0:
        printf("Khong co phan tu nao nho hon 0 trong mang");
        break;
    default:
        printf("Co %d phan tu nho hon 0 trong mang",dem);
        break;
    }
}

void main()
{
    int size = siZe();

    int List[size];

    input(List,size);
    nhohon0(List,size);
}