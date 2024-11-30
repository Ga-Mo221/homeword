#include <stdio.h>

double getAverage(int array[], int size) {
int i;
double avg;
double sum = 0;

    for(i = 0; i < size; i = i + 1) 
    {
        sum = sum + array[i];
    }

    avg = sum / size;
    return avg;
}

void main() 
{
    int ageArray[5] = {50, 100, 25, 87, 44};
    double average;

    average = getAverage(ageArray, 5);

    printf("Average age is: %f ", average);
}
