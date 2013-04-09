/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include "header.h"
/* STATUS: INCOMPLETE */

/* A function to compute ANF */
void ANF ( ulong *M, ulong m ) {
	ulong i, j = 0;
	int tempMAX, index = 0;
	ulong n = 1ul << m;
	ulong * count, * hammingWeight;
	count = ( ulong * ) malloc ( n * sizeof (m) );
	hammingWeight = ( ulong * ) malloc ( n * sizeof (m) );

	for ( i = 0; i < n; i++ ) {
		if ( M[i] == 1 )
			count[i] = i + 1;

		else
			count[i] = 0;
	}	

	for ( i = 0; i < n; i++ ) {
		if ( count[i] > 1 )
			hammingWeight[i] = hamming_weight (count[i]);
	}

	tempMAX = hammingWeight[0];
	for ( i = 0; i < n; i++ ) {
		if ( tempMAX < hammingWeight[i] ) {
			tempMAX = hammingWeight[i];
			index = i + 1;
		}
	}
	
	printf ("This boolean function: ");
	for ( i = 0; i < n; i++ ) {

		while ( hammingWeight[i] > 0 ) {

			if ( ( hammingWeight[i] & 1 )  == 1 )
				printf ("x%d ", j);

			j = j + 1;
		}

		printf ("+");
		j = 0;
	}

	printf ("The maximum degree of given boolean function is %d\n", index);

	free (hammingWeight);
	free (M);
	free (count);

}

int main ( ) {
	ulong * M;
	ulong m, i;

	printf ("Enter the value of m: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;
	M = ( ulong * ) malloc ( n * sizeof (ulong) );

	for ( i = 0; i < n; i++ ) {
		printf ("Enter the value of [%lu]th boolean function: ", i);
		scanf ("%lu", &M[i]);
		if ( M[i] != 0 && M[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	ANF (M, m);
	free (M);
	return 0;
}
