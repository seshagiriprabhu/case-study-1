/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include "header.h"

/* A function to computer the FastWalshTransform */
// It works. Now write a pure function, which returns
// a new array containing the walsh transform
// (or better: which takes an array as a parameter where it puts
// the walsh transform values).
void FastWalshTransform ( int * f, int m ) {
	int * temp_f;
	temp_f = ( int * ) malloc ( pow2 (m) * sizeof(int) );
	int u, j, temp = m, count = 0;
	int split, tempSplit;

	/* Replaces all the values of the function by their sign */
	for ( u = 0; u < pow2 (m); u++ ) 
		temp_f[u] = f[u] = sign(f[u]);
	temp = temp - 1;

	while ( temp > -1 ) {	
            // split is then equal to pow2(m), right??
		split = pow2 (m) / ( pow2 (m) / pow2 (m) );
		tempSplit = split;
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
				tempSplit = tempSplit + pow2 (m);
				count = 0;
			}
		}
		temp = temp - 1;
	}
	free (temp_f);
}

int main ( ) {
	int * f;
	int m, i;

	printf ("Enter the value of m : ");
	scanf ("%d", &m);

	f = ( int * ) malloc ( pow2 (m) * sizeof ( int ) );

	for ( i = 0; i < pow2 (m); i++ ) {
		printf ("Enter the value of [%d] of boolean funciton: ", i + 1);
		scanf  ("%d", &f[i]);
	}

	FastWalshTransform (f, m);
	free (f);
	return 0;
}
