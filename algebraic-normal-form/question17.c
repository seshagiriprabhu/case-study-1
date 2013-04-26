/* Written by Giri
 * An implementation of ANF_eval function */

#include "header.h"
/* STATUS : COMPLETE */

int main () {
	ulong m, u, x;
	ulong *A; 
	printf ("Enter the number of variables in your boolean function: ");
	scanf ("%lu", &m);
	A = allocate_table (m);
	ulong n = 1UL << m;
	for ( u = 0; u < n; u++ ) {
		printf ("Enter the [%lu] boolean value: ", u);
		scanf ("%lu", &A[u]);
	}
	printf ("Enter the integer (x) at which you want to evaluate the Boolean function: ");
	scanf ("%lu", &x);
	if ( ANF_eval (A, x, m) )
		printf ("%lu is an integer of the given ANF\n", x);
	else
		printf ("%lu is not an integer of the given ANF\n", x);
	return 0;
}
