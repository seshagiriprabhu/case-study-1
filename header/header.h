#ifndef HEADER_H
#define HEADER_H

/*-----------Standard header files------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*------------------Macros--------------------*/
#define UL unsigned long
#define LL long long

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

/* A function to calculate the power of 2 */
UL pow2 ( int power ) {
	if ( power == 0 )
		return 1;

	return 2 << (power - 1);
}

/* A function to invert the sign of a binary */
int sign ( UL e ) {
	if ( e & 1 )
		return -1;
	return 1;
}

/* A function to calculate the scalar product of two vectors */
UL scalar_product ( UL *table_f1, UL *table_f2, UL m ) {
	UL i, product = 0;
	for ( i = 0; i < pow2 (m); i++ ) 
		product = product + ( table_f1[i] * table_f2[i] );
	return product;
}

#endif
