/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"
/* STATUS: INCOMPLETE */
/* A function to computer the FastWalshTransform */
int * FastWalshTransform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	ulong n = 1ul << m;
	ulong u, j;
	ulong split, tempSplit;
	temp_f = ( int * ) malloc ( n * sizeof (int) );

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

int main ( ) {
	int *f;
	int *fastWalsh_f;
	ulong m, i;
	printf ("Enter the number of variables in your boolean function : ");
	scanf ("%lu", &m);

	ulong n = 1ul << m;
	f = ( int * ) malloc ( n * sizeof ( int ) );
	fastWalsh_f = ( int * ) malloc ( n * sizeof ( int ) );

	for ( i = 0; i < n; i++ ) {
		printf ("Enter the value of [%lu] of boolean funciton: ", i);
		scanf  ("%d", &f[i]);
	}

	fastWalsh_f = FastWalshTransform (f, m);

	for ( i = 0; i < n; i++ ) {
		if ( i == 0 )
			printf ("\n%d\t", fastWalsh_f[i]);
		else
			printf ("%d\t", fastWalsh_f[i]);
	}
	printf ("\n");
	free (f);
	return 0;
}
