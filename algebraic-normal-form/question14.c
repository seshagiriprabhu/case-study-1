/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include "header.h"
/* STATUS: INCOMPLETE */

/* A function to implement the monomial degree */
ulong * monomial_degree ( ulong * M, ulong m ) {
	ulong i;
	for ( i = 0; i < ( 1ul << m ) ; i++ ) 
		printf ("The monomial degree of [%lu] is %lu\n", M[i], hamming_weight (M[i]));
}

int main () {
	ulong * M;
	ulong m, i;
	ulong n = 1ul << m;
	printf ("Enter the number of variables in your boolean function: ");
	scanf ("%lu", &m);

	M = ( ulong * ) malloc ( n * sizeof ( ulong ) );

	for ( i = 0; i < n; i++) {
		printf ("Enter the [%lu] monomial: ", i);
		scanf ("%lu", &M[i]);
	}
	
	monomial_degree(M, m);
	free(M);
	return 0;
}

