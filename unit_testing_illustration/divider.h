#pragma once
#include <stdio.h>

typedef struct  {

    unsigned quotient;
    unsigned remainder;

} divider_s;

void divide(divider_s*, unsigned, unsigned);
