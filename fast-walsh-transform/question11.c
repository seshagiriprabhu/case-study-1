/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"
/* STATUS: COMPLETE */

/* A function to computer the FastWalshTransform */
long * FastWalshTransform ( long *f, ulong m1 ) {
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

int main ( ) {
	long *f;
	ulong m, i;
	printf ("Enter the number of variables in your boolean function : ");
	scanf ("%lu", &m);
	assert (m <= 30);
	ulong n = 1UL << m;
	f = allocate_long_table (m);
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the value of [%lu] of boolean funciton: ", i);
		scanf  ("%ld", &f[i]);
		if ( f[i] != 0 && f[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}
	f = FastWalshTransform (f, m);
	printf ("\n");
	for ( i = 0; i < n; i++ ) 
		printf ("%ld\t", f[i]);
	printf ("\n");
	return 0;
}
