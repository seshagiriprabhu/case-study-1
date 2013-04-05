/* Written by giri
 * An implememtation of a  function monomial_eval(M, x) which evaluates 
 * a monomial M at point x ∈ (F2)^m */

#include <stdio.h>
#include <stdlib.h>

/* A function to calculate the hamming weight */
int hamming_weight ( unsigned int M ) {
	int count = 0;

	while ( M > 0 ) {
		if ( ( M & 1 ) == 1 )
			count = count + 1;

		M = M >> 1;
	}
	return count;
}

/* A function to calculate the power of a given integer */
int powerFunction ( int number, int power ) { 
	if ( power == 0 )
		return 1;

	else
		return number << ( power - 1 );
}

/* A function to evaluate a Monomial */
void monomial_eval ( unsigned int M, int * x ) {
	int i, tempx = 0;
	
	for ( i = 0; i < ( sizeof (x) / sizeof (int) ); i++ ) 
		tempx = tempx + powerFunction (2, x[i]);
	
	if ( tempx == M )
		printf ("Given variables can be represented by the monomial %d\n", M);

	else
		printf ("Given variables cannot be represented by the monomial %d\n", M);	
}
	

int main ( int argc, char ** argv ) {
	unsigned int M;
	int i, var;
	int * x;

	printf ("Enter the monomial: ");
	scanf ("%du", &M);

	printf ("Enter the number of variables: ");
	scanf ("%d", &var);

	x = ( int * ) malloc ( var * sizeof ( int ) );

	for ( i = 0; i < var; i++ ) {
		printf ("Enter the [%d] variable suffix: ", i + 1);
		scanf ("%d", &x[i]);
	}

	monomial_eval (M, x);
	return 0;
}

