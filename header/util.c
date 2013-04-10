#include "header.h"

/* A function to calculate the hamming weight of a given number */
ulong hamming_weight ( ulong u ) {
	ulong count = 0;
	while ( u > 0 ) {
		if ( u & 1UL )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

/* A function to calculate the power of 2 */
ulong pow2 ( int power ) {
	return 1UL << power;
}

/* A function to invert the sign of a binary */
int sign ( ulong e ) {
	return 1 -  ( 2 * ( e % 2 ) );
}

/* A function to calculate the scalar product of two vectors */
ulong scalar_product ( ulong *table_f1, ulong *table_f2, ulong m ) {
	ulong i, product = 0;
	ulong n = 1UL << m;
	for ( i = 0; i < n; i++ ) 
		product = product + ( table_f1[i] * table_f2[i] );
	return product;
}

/* A function to calculate the hamming weight of a boolean function */
ulong table_hamming_weight ( ulong *val, ulong m ) {
	ulong i, total_weight = 0;
	ulong n = 1UL << m;
	for ( i = 0; i < n; i++ ) 
			total_weight  = total_weight + val[i];
	return total_weight;
}

/* Allocates a ulong binary vector table */
ulong * allocate_table ( ulong m ) {
	return ( ( ulong * ) malloc ( ( 1UL << m ) * sizeof (ulong) ));
}

/* Allocates a long binary vector table - only used for fast walsh */
long * allocate_long_table ( ulong m ) {
	return ( ( long * ) malloc ( ( 1UL << m ) * sizeof (long) ));
}

/* A function to calculate the product of two boolean vectors 
 * given as integers */
// I don't get this function!
// This is the multiplication of two UL using bitwise operators
// I don't whether it is an efficient way or not!
ulong integer_product ( ulong a, ulong x ) {
	ulong result = 0;
	while ( x != 0UL ) { 		// Iterate till x == 0
		if ( x & 1UL )			// 
			result = result + a; // add a to result if x is odd
		a = a << 1UL;			 // Left shift the value in a by one. i.e multiplies a by 2 each tim
		x = x >> 1UL;			// right shift the value in x by one
	}
	return result; // as we need to pass a binary value to sign function, I thought its better to send it from here itself
}

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
/* STATUS: INCOMPLETE */
long * walsh_transform ( long *f, long m ) {
	long *temp_f;
	assert (m <= 30);
	long count = 0, temp = m;
	ulong n = 1UL << m;
	ulong u, j;
	ulong split, tempSplit;
	temp_f = allocate_long_table (m);

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
