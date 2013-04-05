/* Written by giri
 * An implememtation of a  function monomial_eval(M, x) which evaluates 
 * a monomial M at point x ∈ (F2)^m */

#include <stdio.h>
#include <stdlib.h>

/* A function to calculate the hamming weight */
int hamming_weight ( unsigned int M ) {
	int count = 0;

	while ( M > 0 ) {
		if ( ( M & 1 ) == 1 )
			count = count + 1;

		M = M >> 1;
	}
	return count;
}

int main ( int argc, char ** argv ) {
	return 0;
}

