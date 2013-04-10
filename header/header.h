#ifndef HEADER_H
#define HEADER_H

/*-----------Standard header files------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
/*------------------Macros--------------------*/
typedef int bool;
#define true 1
#define false 0

typedef unsigned long ulong;
typedef long long llong;

ulong hamming_weight (ulong u);
ulong pow2 (int power);
int sign (ulong e);
ulong * allocate_table (ulong m);
long * allocate_long_table (ulong m);
ulong scalar_product (ulong *table_f1, ulong *table_f2, ulong m);
ulong integer_product (ulong vector1, ulong vector2);
long * walsh_transform (long *f, ulong m);
ulong table_hamming_weight (ulong *val, ulong m);
#endif
