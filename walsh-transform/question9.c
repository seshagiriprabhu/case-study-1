/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include "header.h"
/* LL is long long */
/* Converts the given Unsigned integer to a binary arrray of size 2**m 
 * such that it can be used for scalar product with boolean function a */
UL * UL_to_binary_array ( UL x, UL m ) {
	UL i = 0, j; 
	UL *xBinary;
	xBinary = ( UL * ) malloc ( pow2 (m) * sizeof ( UL ));
	while ( x > 0 ) {
		if ( x & 1 ) 
			xBinary[i] = 1;
		else 
			xBinary[i] = 0;
		i = i + 1;
		x = x >> 1;
	}
	for ( j = i; j < pow2 (m); j++ )
		xBinary[j] = 0;
	return xBinary;
}

/* Return value is long long because it should hold values from -2**m to 2**m */
LL WalshTransform ( UL *f, UL *a, UL m ) {
	UL i, scalarProduct;						/* Holds the result of scalarProduct between a and x) */
	LL signResult; 								/* Holds the result of sign function (-1)**(f(x) + a.x) */
	LL output = 0; 								/* Holds the result of sigma function */
	for ( i = 0; i < pow2 (m); i++ ) {
		scalarProduct = scalar_product (a, UL_to_binary_array (i, m), m); 
		scalarProduct = hamming_weight(scalarProduct) % 2;  /* Modulo 2 is performed */
		signResult =  sign ( (f[i] + scalarProduct) % 2 );  /* Sign values can take only 0 and 1 that's why modulo 2*/
		output = output + signResult;
	}
	return output;
}

int main () {
	UL *table_f1;
	UL *a;
	UL m, i, j;

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);

	table_f1 = ( UL * ) malloc ( pow2 (m) * sizeof (UL) );
	a =  ( UL * ) malloc ( pow2 (m) * sizeof (UL) );
	
	for ( i = 0; i < pow2 (m); i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function f: ", i);
		scanf ("%lu", &table_f1[i]);
		if ( table_f1[i] != 0 && table_f1[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	for ( i = 0; i < pow2 (m); i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function a: ", i);
		scanf ("%lu", &a[i]);
		if ( a[i] != 0 && a[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	printf ("Truth Table\n");
	printf ("f\ta\n");

	for ( i = 0; i < pow2 (m); i++ ) {
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
