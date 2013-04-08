/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include "header.h"

/* A function to implement the monomial degree */
void monomial_degree ( unsigned int * M, int m ) {
	int i;

	for ( i = 0; i < m; i++ ) 
		printf ("The monomial degree of [%d] is %d\n", M[i], hamming_weight (M[i]));

}

int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("How many monomial degrees you want to calculate: ");
	scanf ("%d", &m);

	M = ( unsigned int * ) malloc ( m * sizeof ( unsigned int ) );

	for ( i = 0; i < m; i++) {
		printf ("Enter the [%d] monomial: ", i + 1);
		scanf ("%du", &M[i]);
	}
	
	monomial_degree(M, m);
	free(M);
	return 0;
}

