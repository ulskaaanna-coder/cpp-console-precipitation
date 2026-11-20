#ifndef FILTER_H
#define FILTER_H

#include "precipitation.h"

precipitation** filter(precipitation* array[], int size, bool (*check)(precipitation* element), int& result_size);

bool check_is_rain(precipitation* element);
bool check_amount_less_1_5(precipitation* element);

#endif
