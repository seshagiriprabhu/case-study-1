/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include "header.h"
/* Converts the given Unsigned integer to a binary arrray of size 2**m 
 * such that it can be used for scalar product with boolean function a */
ulong * ulong_to_binary_array ( ulong x, ulong m ) {
	ulong i = 0, j; 
	ulong *xBinary;
	ulong n = 1ul << m;
	xBinary = ( ulong * ) malloc ( n * sizeof ( ulong ));
	while ( x > 0 ) {
		if ( x & 1 ) 
			xBinary[i] = 1;
		else 
			xBinary[i] = 0;
		i = i + 1;
		x = x >> 1;
	}
	for ( j = i; j < n; j++ )
		xBinary[j] = 0;
	return xBinary;
}

/* Return value is long long because it should hold values from -2**m to 2**m */
// Why do we need long long?

// you have to reread the question :
// a is a binary vector, given as an integer...
// you should rewrite scalarProduct for integers.

llong WalshTransform ( ulong *f, ulong *a, ulong m ) {
	llong i, scalarProduct;						/* Holds the result of scalarProduct between a and x) */
	llong signResult; 								/* Holds the result of sign function (-1)**(f(x) + a.x) */
	llong output = 0; 								/* Holds the result of sigma function */
	for ( i = 0; i < pow2 (m); i++ ) {
		scalarProduct = scalar_product (a, ulong_to_binary_array (i, m), m); 
		scalarProduct = hamming_weight(scalarProduct) % 2;  /* Modulo 2 is performed */
		signResult =  sign ( (f[i] + scalarProduct) % 2 );  /* Sign values can take only 0 and 1 that's why modulo 2*/
		output = output + signResult;
	}
	return output;
}

int main () {
	ulong *table_f1;
	ulong *a;
	ulong m, i, j;

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;

	table_f1 = ( ulong * ) malloc ( n * sizeof (ulong) );
	a =  ( ulong * ) malloc ( n * sizeof (ulong) );
	
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function f: ", i);
		scanf ("%lu", &table_f1[i]);
		if ( table_f1[i] != 0 && table_f1[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function a: ", i);
		scanf ("%lu", &a[i]);
		if ( a[i] != 0 && a[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	printf ("Truth Table\n");
	printf ("f\ta\n");

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 ) 
				printf ("%lu\t", table_f1[i]);			
			else 
				printf ("%lu\n", a[i]);
		}	
	}

	printf ("The walsh transform of the given vector is %lld\n", WalshTransform (table_f1, a, m));
	return 0;
}
