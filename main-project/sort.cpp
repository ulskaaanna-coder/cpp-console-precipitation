#include "sort.h"
#include <cstring>

int compare_by_amount(precipitation* a, precipitation* b)
{
    if (a->amount < b->amount) return -1;
    if (a->amount > b->amount) return 1;
    return 0;
}

int compare_by_characteristic_and_date(precipitation* a, precipitation* b)
{
    int char_cmp = strcmp(a->characteristic, b->characteristic);
    if (char_cmp != 0)
    {
        return char_cmp;
    }
    if (a->month != b->month)
    {
        return (a->month < b->month) ? -1 : 1;
    }
    if (a->day != b->day)
    {
        return (a->day < b->day) ? -1 : 1;
    }
    return 0;
}

void shaker_sort(precipitation* array[], int size, int (*cmp)(precipitation* a, precipitation* b))
{
    int left = 0;
    int right = size - 1;
    bool swapped = true;

    while (left < right&& swapped)
    {
        swapped = false;
        for (int i = left; i < right; i++)
        {
            if (cmp(array[i], array[i + 1]) > 0)
            {
                precipitation* temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (cmp(array[i - 1], array[i]) > 0)
            {
                precipitation* temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
                swapped = true;
            }
        }
        left++;
    }
}

static void quick_sort_recursive(precipitation* array[], int left, int right, int (*cmp)(precipitation* a, precipitation* b))
{
    int i = left;
    int j = right;
    precipitation* pivot = array[(left + right) / 2];

    while (i <= j)
    {
        while (cmp(array[i], pivot) < 0) i++;
        while (cmp(array[j], pivot) > 0) j--;
        if (i <= j)
        {
            precipitation* temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quick_sort_recursive(array, left, j, cmp);
    if (i < right) quick_sort_recursive(array, i, right, cmp);
}

void quick_sort(precipitation* array[], int size, int (*cmp)(precipitation* a, precipitation* b))
{
    if (size > 1)
    {
        quick_sort_recursive(array, 0, size - 1, cmp);
    }
}
