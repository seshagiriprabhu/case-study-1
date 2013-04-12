/* Written by giri
 * An implememtation of a  function monomial_eval(M, x) which evaluates 
 * a monomial M at point x ∈ (F2)^m */

#include "header.h"
/* STATUS: INCOMPLETE */

int main ( ) {
	ulong M;
	ulong x;

	printf ("Enter the monomial: ");
	scanf ("%lu", &M);

	printf ("Enter the value of x: ");
	scanf ("%lu", &x);

	if ( monomial_eval (M, x) )
		printf ("%lu is a variable of the given monomial %lu\n", x, M);
	else
		printf ("%lu is not a variable of the given  monomial %lu\n", x, M);	

	return 0;
}
