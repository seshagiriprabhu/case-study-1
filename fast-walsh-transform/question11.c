/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"
/* STATUS: COMPLETE */

/* A function to computer the FastWalshTransform */
long * FastWalshTransform ( long *f, ulong m1 ) {
	long  a, m = m1;
	ulong u, v, split, tempSplit, n = 1UL << m;

	for ( u = 0; u < n; u++ ) 
		f[u] = ( 1 - 2 * f[u] );

	for ( m = m - 1; m >= 0; m--  ) {
    	split = 1UL << m ;
        for ( u = 0; u < n; u += 2 * split ) {
        	tempSplit = u + split;
			for ( v=u; v < tempSplit; v++ ) {
				a = f[v] + f[v + split];
				f[v + split] = f[v] - f[v + split];
				f[v] = a;
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
