#include "header.h"

/* This function checks whether the first binary is position is 0 or 1 */
bool check_first_bit ( ulong bit ) {
	return ( bit & 1UL );
}

/* This function checks the value of the given integer's ith the binary 
   position */
bool check_random_bit ( ulong bit,  ulong i ) {
	return ( ( bit >> i ) & 1UL );
}

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
ulong integer_product ( ulong a, ulong x ) {
	ulong result = 0;
	while ( x != 0UL || a != 0UL ) { 	
		if ( x & 1UL && a & 1UL )	
			result = result + 1;
		a = a >> 1UL;			
		x = x >> 1UL;	
	}
	return result;
}

/* Another approach to the integer product */
ulong integer_product_alternative ( ulong a, ulong x ) {
	ulong result = a & x;
	return hamming_weight (result);
}

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
/* STATUS: COMPLETE */
long * walsh_transform ( long *f, ulong m1 ) {
	long  a, m = m1;
	ulong u, split, tempSplit, n = 1UL << m;
	split = tempSplit = ( 1UL << (m - 1) );

	for ( u = 0; u < n; u++ ) 
		f[u] = ( 1 - 2 * f[u] );

	for ( m = m - 1; m > -1; m--, tempSplit = split = ( 1UL << m ) ) {
		for ( u = 0; u < n; u += split, tempSplit += 2 * split ) {
			for ( ; u < tempSplit; u++ ) {
				a = f[u] + f[u + (1UL << m)];
				f[u + (1UL << m)] = f[u] - f[u + (1UL << m)];
				f[u] = a;
			}
		}
	} 
	return f;
}

/* A function to implement the monomial degree */
ulong monomial_degree ( ulong M ) {
	return hamming_weight (M);	
}

/* A function to evaluate a Monomial */
bool monomial_eval ( ulong M, ulong x ) {
	return check_random_bit (M, x);
}
