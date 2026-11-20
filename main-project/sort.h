#ifndef SORT_H
#define SORT_H

#include "precipitation.h"

int compare_by_amount(precipitation* a, precipitation* b);
int compare_by_characteristic_and_date(precipitation* a, precipitation* b);

void shaker_sort(precipitation* array[], int size, int (*cmp)(precipitation* a, precipitation* b));
void quick_sort(precipitation* array[], int size, int (*cmp)(precipitation* a, precipitation* b));

#endif
