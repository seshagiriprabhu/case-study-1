/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include <stdio.h>
#include <stdlib.h>

/* A function to implement the monomial degree */
void monomial_degree ( unsigned int M, int m ) {
	int i;

}

int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("Enter the number of variables in the monomial: ");
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

