/* Written by giri
 * An implememtation of a  function monomial_eval(M, x) which evaluates 
 * a monomial M at point x ∈ (F2)^m */

#include <stdio.h>
#include <stdlib.h>

/* A function to evaluate a Monomial */
void monomial_eval ( unsigned int M, int x ) {
	if ( ( M >> x ) & 1 )
		printf ("Given variables can be represented by the monomial %d\n", M);

	else
		printf ("Given variables cannot be represented by the monomial %d\n", M);	
}
	

int main ( int argc, char ** argv ) {
	unsigned int M;
	int x;

	printf ("Enter the monomial: ");
	scanf ("%du", &M);

	printf ("Enter the value of x: ");
	scanf ("%d", &x);

	monomial_eval (M, x);
	return 0;
}

