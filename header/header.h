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

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
int * walsh_transform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	UL n = pow2 (m);
	UL u, j;
	UL split, tempSplit;
	temp_f = ( int * ) malloc ( n * sizeof(int) );

	for ( u = 0; u < n; u++ ) 
		temp_f[u] = f[u] = sign(f[u]);

	temp = temp - 1;
	while ( temp > -1 ) {	
		tempSplit = split = pow2 (temp) ;
		for ( u = 0; u < n; u = u + split ) {
			for ( j = u; j < u + split; j++ ) {
				if ( j < tempSplit ) 
					temp_f[j] =  f[j] + f[ ( j + split ) % n ] ; 
				else  
					temp_f[j] = f [ j - split ] - f[j]; 
			}
			count = count + 1;
			if (count == 2) {
				tempSplit = tempSplit + pow2 (split);
				count = 0;
			}
		}
		for ( u = 0; u < n; u++ )
			f[u] = temp_f[u];

		temp = temp - 1;
	}
	free (temp_f);
	return temp_f;
}
#endif
