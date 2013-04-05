/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include <stdio.h>
#include <stdlib.h>

/* A function to calculate the power of a given number */
int powerFunction ( int number, int power ) {
	if ( power == 0 )
		return 1;

	else 
		return number << ( power - 1 );
}

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
void ANF ( unsigned int * M, int m) {
	int i, j = 0, tempMAX, index = 0;

	int * count, * hammingWeight;
	count = ( int * ) malloc ( powerFunction (2, m) * sizeof (m) );
	hammingWeight = ( int * ) malloc ( powerFunction (2, m) * sizeof (m) );

	for ( i = 0; i < powerFunction (2, m); i++ ) {
		if ( M[i] == 1 )
			count[i] = i + 1;

		else
			count[i] = 0;
	}	

	for ( i = 0; i < powerFunction (2, m); i++ ) {
		if ( count[i] > 1 )
			hammingWeight[i] = hamming_weight (count[i]);
	}

	tempMAX =hammingWeight[0];
	for ( i = 0; i < powerFunction (2, m); i++ ) {
		if ( tempMAX < hammingWeight[i] ) {
			tempMAX = hammingWeight[i];
			index = i + 1;
		}
	}
	
	printf ("This boolean function: ");
	for ( i = 0; i < powerFunction(2, m); i++ ) {

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

int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	M = ( unsigned int * ) malloc ( powerFunction(2, m) * sizeof ( unsigned int) );

	for ( i = 0; i < powerFunction(2, m); i++ ) {
		printf ("Enter the value of [%d]th boolean function: ", i + 1);
		scanf ("%du", &M[i]);
	}

	ANF (M, m);
	free (M);
	return 0;
}
