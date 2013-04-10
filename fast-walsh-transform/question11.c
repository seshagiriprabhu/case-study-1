/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"
/* STATUS: INCOMPLETE */

/* A function to computer the FastWalshTransform */
long * FastWalshTransform ( long *f, ulong m ) {
	long *temp_f;
	long count = 0, temp = m;
	ulong n = 1UL << m;
	ulong u, j;
	ulong split, tempSplit;
	temp_f = allocate_long_table (m);

	for ( u = 0; u < n; u++ ) 
		temp_f[u] = f[u] = ( 1 - 2 * f[u] );

	temp = temp - 1;
	while ( temp > -1 ) {	
		tempSplit = split = pow2 (temp) ;
                // this algo below, with tempSplit and count, and with
                // "% pow2 (m)", seems over-complicated. There is a simpler solution.
		for ( u = 0; u < n; u = u + split ) {
			for ( j = u; j < u + split; j++ ) {
				if ( j < tempSplit ) 
					temp_f[j] =  f[j] + f[ ( j + split ) ] ; 
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

int main ( ) {
	long *f;
	long *fastWalsh_f;
	ulong m, i;
	printf ("Enter the number of variables in your boolean function : ");
	scanf ("%lu", &m);
	assert (m <= 30);
	ulong n = 1UL << m;
	f = allocate_long_table (m);
	fastWalsh_f = allocate_long_table (m);

	for ( i = 0; i < n; i++ ) {
		printf ("Enter the value of [%lu] of boolean funciton: ", i);
		scanf  ("%ld", &f[i]);
	}

	fastWalsh_f = FastWalshTransform (f, m);

	for ( i = 0; i < n; i++ ) {
		if ( i == 0 )
			printf ("\n%ld\t", fastWalsh_f[i]);
		else
			printf ("%ld\t", fastWalsh_f[i]);
	}
	printf ("\n");
	free (f);
	return 0;
}
