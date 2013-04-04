/* Written by Giri
 * Implementation of non-linearity funciton */

#include <stdio.h>

/* A function to calculate the power of given integer */
int powerFunction ( int number, int power ) {
	if ( power == 0 ) 
		return 1;
	else
		return number << ( m  - 1 );
}

/* A function to calculate the hamming weight of a boolean function */
int hamming_weight ( unsigned int u ) {
	int count = 0;

	while ( u > 0 ) {
		if ( ( u & 1 ) == 0 )
			count = count + 1
		u = u >> 1;
	}

	return count;
}

int main ( int argc, char ** argv ) {
	unsigned int * u;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	u = ( unsigned int * ) malloc ( m * sizeof ( unsigned int ) );
	
	for ( i = 0; i < powerFunction (2, m); i++ ) {
		printf ("Enter the [%d]th boolean value of boolean function: ");
		scanf ("%du", &u[i]);
	}

	return 0;
}

