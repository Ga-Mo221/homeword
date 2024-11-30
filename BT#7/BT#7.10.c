#include <stdio.h>
#include <conio.h>
#include <string.h>

void inputarray(float arr[3][6], char hs[][20], char mon[][10])
{
    for (int i = 0; i < 3; i++)
    {
        printf("%s \n", hs[i]);
        for (int j = 0; j < 6; j++)
        {
            printf("%s", mon[j]);
            if (j == 5)
            {
                float sum = 0;
                for (int stt = 0; stt < 5; stt++)
                {
                    sum += arr[i][stt];
                }
                float avg = sum / 5;
                printf("%.1f\n", avg);
                arr[i][j] = avg;
            }
            else
            {
                // Kiểm tra đầu vào để đảm bảo giá trị hợp lệ
                while (scanf("%f", &arr[i][j]) != 1) {
                    printf("Vui lòng nhập một số hợp lệ: ");
                    while(getchar() != '\n'); // Xóa bộ đệm
                }
            }
        }
    }
}

void outputarray(float arr[3][6], char hs[][20])
{
    printf("\nStudent    |   CF   |   BPL  |   OOP  |   NPF  |  RDBMS |   AVG  |  GRADE ");
    printf("\n-----------------------------------------------------------------------");
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s", hs[i]);
        for (int j = 0; j < 6; j++)
        {
            printf("  %.1f   |", arr[i][j]);
            if (j == 5)
            {
                int dtb = (arr[i][j] / 25) * 100;
                char* grades[] = {"F", "D", "C", "B", "A"};
                int index = (dtb < 50) ? 0 : (dtb < 65) ? 1 : (dtb < 80) ? 2 : (dtb < 90) ? 3 : 4;
                printf("%s \n", grades[index]);
            }
        }
    }
}

void main()
{
    float bangdiem[3][6];
    char mon[6][10] = {"CF : ", "BPL: ", "OOP: ", "NPE: ", "RDBMS: ", "VAG : "};
    char hocsinh[3][20] = {"hoc sinh 1 |", "hoc sinh 2 |", "hoc sinh 3 |"};

    inputarray(bangdiem, hocsinh, mon);
    outputarray(bangdiem, hocsinh);

    getch();
}
