/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"

/* A function to computer the FastWalshTransform */
int * FastWalshTransform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	UL u, j;
	UL split, tempSplit;
	temp_f = ( int * ) malloc ( pow2 (m) * sizeof(int) );

	/* Replaces all the values of the function by their sign */
	for ( u = 0; u < pow2 (m); u++ ) 
		temp_f[u] = f[u] = sign(f[u]);

	temp = temp - 1;
	while ( temp > -1 ) {	
		tempSplit = split = pow2 (temp) ;
                // this algo below, with tempSplit and count, and with
                // "% pow2 (m)", seems over-complicated. There is a simpler solution.
		for ( u = 0; u < pow2 (m); u = u + split ) {
			for ( j = u; j < u + split; j++ ) {

				/* if the current  index is less than the split value, it adds the boolean values */
				if ( j < tempSplit ) 
					temp_f[j] =  f[j] + f[ ( j + split ) % pow2 (m) ] ; 

				/* if the current index is greater than the split value, it takes the difference 
				 * of the boolean values */
				else  
					temp_f[j] = f [ j - split ] - f[j]; 
			}

			/* Re-assigns the temp split value after two iterations 
			 * i.e after completing one round of addition operations (f[u] + f[u + split ]
			 * and difference operation (f[u] - f[u - split]) */
			count = count + 1;
			if (count == 2) {
				tempSplit = tempSplit + pow2 (split);
				count = 0;
			}
		}

		for ( u = 0; u < pow2 (m); u++ )
			f[u] = temp_f[u];

		temp = temp - 1;
	}
	free (temp_f);
	return temp_f;
}

int main ( ) {
	int *f;
	int *fastWalsh_f;
	UL m, i;

	printf ("Enter the number of variables in your boolean function : ");
	scanf ("%lu", &m);

	f = ( int * ) malloc ( pow2 (m) * sizeof ( int ) );
	fastWalsh_f = ( int * ) malloc ( pow2 (m) * sizeof ( int ) );

	for ( i = 0; i < pow2 (m); i++ ) {
		printf ("Enter the value of [%lu] of boolean funciton: ", i);
		scanf  ("%d", &f[i]);
	}

	fastWalsh_f = FastWalshTransform (f, m);

	for ( i = 0; i < pow2 (m); i++ ) {
		if ( i == 0 )
			printf ("\n%d\t", fastWalsh_f[i]);
		else
			printf ("%d\t", fastWalsh_f[i]);
	}
	printf ("\n");
	free (f);
	return 0;
}
