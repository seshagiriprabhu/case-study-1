/* Written by giri
 * A function taking an ANF and computes the maximum 
 * degree of its monomial */

#include "header.h"
/* STATUS: INCOMPLETE */

/* A function to compute ANF */
ulong ANF (ulong *M, ulong m) {

}

int main ( ) {
	ulong * M;
	ulong m, i;
	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;
	M = allocate_table (m);
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the value of [%lu]th boolean function: ", i);
		scanf ("%lu", &M[i]);
		if ( M[i] != 0 && M[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}
	printf ("The ANF of given binary function is %lu\n", ANF (M, m);
	free (M);
	return 0;
}
