/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include <stdio.h>
#include <stdlib.h>

/* A function to find the hamming weight */
int hamming_weight ( int number ) {
	int count = 0;

	while ( number > 0 ) {

		if ( ( number & 1 ) == 1 )
			count = count + 1;

		number = number >> 1;
	}

	return count;
}

/* A function to compute ANF */
void ANF ( unsigned int * M, int m, int x ) {
	int i, j = 0, tempMAX, index = 0;

	int * count, * hammingWeight;
	count = ( int * ) malloc ( m * sizeof (m) );
	hammingWeight = ( int * ) malloc ( m * sizeof (m) );

	for ( i = 0; i < m; i++ ) {
		if ( M[i] == 1 )
			count[i] = i + 1;

		else
			count[i] = 0;
	}	

	for ( i = 0; i < m; i++ ) {
		if ( count[i] > 1 )
			hammingWeight[i] = hamming_weight (count[i]);
	}

	tempMAX =hammingWeight[0];
	for ( i = 0; i < m; i++ ) {
		if ( tempMAX < hammingWeight[i] ) {
			tempMAX = hammingWeight[i];
			index = i + 1;
		}
	}
	
	printf ("This boolean function: ");
	for ( i = 0; i < m; i++ ) {

		while ( hammingWeight[i] > 0 ) {

			if ( ( hammingWeight[i] & 1 )  == 1 )
				printf ("x%d ", j);

			j = j + 1;
		}

		printf ("+");
		j = 0;
	}

	printf ("The maximum degree of given boolean function is %d\n", index);
}

int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	M = ( unsigned int * ) malloc ( m * sizeof ( unsigned int) );

	for ( i = 0; i < m; i++ ) {
		printf ("Enter the value of [%d]th boolean function: ", i + 1);
		scanf ("%du", &M[i]);
	}
	return 0;
}
