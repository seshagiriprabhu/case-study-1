/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include "header.h"
/* STATUS : COMPLETE */

long WalshTransform ( ulong *f, ulong a, ulong m ) {
    assert(m <= 30);
	ulong x, product;
	long output = 0;
	ulong n = 1UL << m;
	for ( x = 0; x < n; x++ ) { 
		product = integer_product (a, x);
		output = output +  sign (f[x] + product);
	}
	return output;
}

int main () {
	ulong *table_f1;
	ulong a, m, i;
	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	table_f1 = allocate_table (m);
	ulong n = 1UL << m;
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function f: ", i);
		scanf ("%lu", &table_f1[i]);
		if ( table_f1[i] != 0 && table_f1[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}
	printf ("Enter the value of a: ");
	scanf ("%lu", &a);
	printf ("The walsh transform of the given vector is %ld\n", WalshTransform (table_f1, a, m));
	return 0;
}
