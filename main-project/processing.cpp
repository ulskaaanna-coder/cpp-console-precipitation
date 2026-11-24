#include "processing.h"

double process(precipitation* array[], int size, int month)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        precipitation* item = *(array + i);
        if (item->month == month)
        {
            sum += item->amount;
        }
    }
    return sum;
}
