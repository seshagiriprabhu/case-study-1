#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int hamming_weight ( unsigned long u ) {
	unsigned long count = 0;

	while ( u > 0 ) {
		if ( ( u & 1) == 1 )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

unsigned int pow2 ( int power ) {
	if ( power == 0 )
		return 1;

	return 2 << (power - 1);
}

#endif
