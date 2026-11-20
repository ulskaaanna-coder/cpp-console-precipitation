#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include "constants.h"

struct precipitation
{
    int day;
    int month;
    double amount;
    char characteristic[MAX_STRING_SIZE];
};

#endif
