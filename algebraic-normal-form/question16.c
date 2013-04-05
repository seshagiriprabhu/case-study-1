/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include <stdio.h>
#include <stdlib.h>


int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	M = ( unsigned int * ) malloc ( m * sizeof ( unsigned int) );

	for ( i = 1; i < m + 1; i++ ) {
		printf ("Enter the value of [%d]: ");
		scanf ("%du", &M[i]);
	}

}
