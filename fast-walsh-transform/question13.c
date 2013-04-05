/* Written by Giri
 * Implementation of non-linearity funciton */

#include <stdio.h>
#include <stdlib.h>

/* A function to calculate the power of given integer */
int powerFunction ( int number, int power ) {
	if ( power == 0 ) 
		return 1;
	else
		return number << ( power  - 1 );
}

/* A function to calculate the hamming weight of a boolean function */
int hamming_weight ( unsigned int u ) {
	int count = 0;

	while ( u > 0 ) {
		if ( ( u & 1 ) == 1 )
			count = count + 1;
		u = u >> 1;
	}

	return count;
}

/* A function to calculate the non-linerity of given boolean funciton  */
void nonlinearity ( unsigned int * u, int m ) {
	int hammingWeight, i, count = 0;

	for ( i = 0; i < powerFunction (2, m); i++ ) {
		hammingWeight = hamming_weight (u[i]);
		if ( hammingWeight > 0 )
			count = count + 1;
	}
	
	if ( ( count - ( powerFunction (2, m) / 2 ) ) < 0 )
		printf ("1 Nonlinerity is %d\n", ( ( powerFunction (2, m) / 2 )- count ));

	else if ( ( count - ( powerFunction (2, m) / 2 ) ) == 0 )
		printf ("2 Nonlinearity is ZERO\n");

	else 
		printf ("3 Nonlinearity is %d\n",  ( count - ( powerFunction (2, m) / 2 ) ));

}

int main ( int argc, char ** argv ) {
	unsigned int * u;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	u = ( unsigned int * ) malloc ( powerFunction (2, m) * sizeof ( unsigned int ) );
	
	for ( i = 0; i < powerFunction (2, m); i++ ) {
		printf ("Enter the [%d]th boolean value of boolean function: ", i + 1);
		scanf ("%du", &u[i]);
	}
	
	nonlinearity (u, m);
	free (u);
	return 0;
}

