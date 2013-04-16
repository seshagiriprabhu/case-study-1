/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include "header.h"
/* STATUS: COMPLETE */

int main () {
	ulong M;
	printf ("Enter the monomial: ");
	scanf ("%lu", &M);
	printf ("The monomial degree of the given monomial %lu is %lu\n", M,  monomial_degree(M)); /* Defined in util.c */
	return 0;
}

