/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include "header.h"

/* A function to implement the monomial degree */
UL * monomial_degree ( UL * M, UL m ) {
	UL i;
	for ( i = 0; i < pow2 (m); i++ ) 
		printf ("The monomial degree of [%lu] is %lu\n", M[i], hamming_weight (M[i]))
}

int main () {
	UL * M;
	UL m, i;

	printf ("Enter the number of variables in your boolean function: ");
	scanf ("%lu", &m);

	M = ( UL * ) malloc ( pow2 (m) * sizeof ( UL ) );

	for ( i = 0; i < pow2 (m); i++) {
		printf ("Enter the [%lu] monomial: ", i);
		scanf ("%lu", &M[i]);
	}
	
	monomial_degree(M, m);
	free(M);
	return 0;
}

