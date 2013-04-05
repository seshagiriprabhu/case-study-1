/* Written by giri
 * Implementation of monomial_degree(M) which computes the degree of a 
 * monomial given as an integer  */

#include <stdio.h>
#include <stdlib.h>

/* A function to find the power of a given number */
int powerFunction ( int number, int power ) {
	if ( power == 0 )
		return 0;
	else 
		return number << ( power - 1 );
}

/* A function to implement the monomial degree */
int monomial_degree ( unsigned int * M ) {
	int i, count = 0;

	for ( i = 0; i < sizeof (M); i++ ) {

	}
}

int main ( int argc, char ** argv ) {
	return 0;
}

