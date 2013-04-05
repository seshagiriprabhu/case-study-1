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
void monomial_eval ( unsigned int M, int x ) {
	int tempx = 0;
	int degree = hamming_weight (M);

	while ( degree > -1 ) {
		tempx = tempx + powerFunction (2, degree);
		degree = degree - 1;
	}

	if ( tempx == x )
		printf ("Given integer X (i.e %d) can be represented by the monomial %d\n", x, M);

	else
		printf ("Given integer X (i.e %d) cannot be represented by the monomial %d\n", x, M);	
}
	

int main ( int argc, char ** argv ) {
	unsigned int M;
	int x;

	printf ("Enter the monomial: ");
	scanf ("%du", &M);

	printf ("Enter the integer (X): ");
	scanf ("%d", x);

	monomial_eval (M, x);
	return 0;
}

