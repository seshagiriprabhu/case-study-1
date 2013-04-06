/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include "header.h"

/* A function to calculate the power of a number */

// Confusing name and confusing comment:
// this function computes number * 2**(power-1)
// (where '**' represents exponentiation).
// In the context of Boolean functions,
// the term "power function" means something
// completely different

// I don't really get what this function is meant for...
// But it has the same name as a different function
// in question8.c, so it is confusing


// Next 2 functions: what is m? there is confusion
// Try to reread the question & revise, and let's discuss if you
// don't understand.
// Also: don't do I/O in functions which should be pure!
// Do I/O in e.g. main.

UL WalshTransform ( UL *f, UL *a, UL m ) {
	UL i, scalarProduct, output = 0;
	for ( i = 0; i < pow2 (m); i++ ) {
		scalarProduct = i * a[i];
		scalarProduct = scalarProduct % 2;
		output = output + (f[i] + scalarProduct); 
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

	printf ("The walsh transform of the given vector is %lu\n", WalshTransform (table_f1, a, m));
	return 0;
}
