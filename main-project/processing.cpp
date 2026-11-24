#include "processing.h"

double process(precipitation* array[], int size, int month)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (array[i]->month == month)
        {
            sum += array[i]->amount;
        }
    }
    return sum;
}

