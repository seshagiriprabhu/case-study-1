#include "header.h"
/*-----------------Functions------------------*/

// I don't remember exactly the rules for C,
// as I use C++, but I think putting function definition
// in header files is bad, at least without marking them
// as 'static' ('inline' in C++). You will have a 'multiple
// definition error' if you build a program made of 2+ object
// files including the code for these functions.
// The usual way to do is to put only declaration of these
// functions in the header file, put their definitions
// in a .c file, say "util.c", and build your programs

/* A function to calculate the hamming weight of a given number */
ulong hamming_weight ( ulong u ) {
	ulong count = 0;
	while ( u > 0 ) {
		if ( ( u & 1) == 1 )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

/* A function to calculate the power of 2 */
ulong pow2 ( int power ) {
	return 1ul << power;
}

/* A function to invert the sign of a binary */
int sign ( ulong e ) {
	return 1 - 2 * e;
}

/* A function to calculate the scalar product of two vectors */
ulong scalar_product ( ulong *table_f1, ulong *table_f2, ulong m ) {
	ulong i, product = 0;
	ulong n = 1ul << m;
	for ( i = 0; i < n; i++ ) 
		product = product + ( table_f1[i] * table_f2[i] );
	return product;
}

/* A function to calculate the hamming weight of a boolean function */
ulong table_hamming_weight ( ulong *val, ulong m ) {
	ulong i, total_weight = 0;
	ulong n = 1ul << n;
	for ( i = 0; i < n; i++ ) 
			total_weight  = total_weight + val[i];
	return total_weight;
}

/* A function to calculate the product of two boolean vectors 
 * given as integers */
// I don't get this function!
bool integer_product ( ulong a, ulong x ) {
	ulong result = 0;
	while ( x > 0 ) {
		if ( x & 1 )
			result = result + a; // ??
		a = a << 1; // ??
		x = x >> 1;
	}
	return result % 2; // ??
}

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
/* STATUS: INCOMPLETE */
int * walsh_transform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	ulong n = pow2 (m);
	ulong u, j;
	ulong split, tempSplit;
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
