/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"
/* STATUS: COMPLETE */

// Very good
// I modified this function, so that :
// 1) you don't have to repeat the line: 	split = tempSplit = ( 1UL << (m - 1) );
// (an alternative would be: split/=2 in the 3rd part of the 'for' (idem for tempSplit)
// 2) you don't modify u in two for loops, which is confusing (well, not that much
// in this case, at least for me as I know very well this algo, but still)
// 3) finally I moved tempSplit only in one place, to cache, the value of u+split,
// I think it is not that necessary (the gain in efficiency should be negligible)
// 4) replace 1<<m by split
// Tell me if you find errors. I would remove tempSplit.

/* A function to computer the FastWalshTransform */
long * FastWalshTransform ( long *f, ulong m1 ) {
	long  a, m = m1;
	ulong u, v, split, tempSplit, n = 1UL << m;

	for ( u = 0; u < n; u++ ) 
		f[u] = ( 1 - 2 * f[u] );

	for ( m = m - 1; m >= 0; m--  ) {
            split = 1UL << m ;
            for ( u = 0; u < n; u += 2*split ) {
                        tempSplit = u+split;
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
