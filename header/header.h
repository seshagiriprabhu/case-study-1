#ifndef HEADER_H
#define HEADER_H

/*-----------Standard header files------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*------------------Macros--------------------*/
#define UL unsigned long

/*-----------------Functions------------------*/

/* A function to calculate the hamming weight of a given number */
UL hamming_weight ( unsigned long u ) {
	UL count = 0;

	while ( u > 0 ) {
		if ( ( u & 1) == 1 )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

UL pow2 ( int power ) {
	if ( power == 0 )
		return 1;

	return 2 << (power - 1);
}

#endif
