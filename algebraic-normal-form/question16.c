/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include <stdio.h>
#include <stdlib.h>

/* A function to compute ANF */
void ANF ( unsigned int * M, int m, int x ) {
	int i;

	int * count;
	count = ( int * ) malloc ( m * sizeof (m) );
	
	for ( i = 0; i < m; i++ ) {
		if ( M[i] == 1 )
			count[i] = i + 1;

		else
			count[i] = 0;
	}	

	for ( i = 0; i < m; i++ ) {
		if ( count[i] > 1 )
	}
		
}

int main ( int argc, char ** argv ) {
	unsigned int * M;
	int m, i;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	M = ( unsigned int * ) malloc ( m * sizeof ( unsigned int) );

	for ( i = 0; i < m; i++ ) {
		printf ("Enter the value of [%d]th boolean function: ");
		scanf ("%du", &M[i]);
	}

}
