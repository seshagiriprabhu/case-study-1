/* Written by Giri
   A function in m variables is said to be balanced if it takes 
   values 0 and 1 the same number of times. What is the Hamming 
   weight of such a Boolean function? Implement a function 
   is_balanced(f) which checks the balancedness of a Boolean 
   function f */

#include "header.h"
/* STATUS: COMPLETE */

bool is_balanced ( ulong *f, ulong m ) {
	ulong count = table_hamming_weight (f, m);
	if ( count == ( ( 1UL << m ) / 2) )
		return 1;
	return 0;
}

int main () {
	ulong *f;
	ulong m, i;
	printf ("Enter the value of m: ");
	scanf ("%lu", &m);
	if ( m == 0) {
		printf ("You must atleast give a value\n");
		exit(0);
	}
	f = allocate_table (m);
	ulong n = 1UL << m;
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu] boolean value of the boolean function: ", i);
		scanf ("%lu", &f[i]);
		if ( f[i] != 0 && f[i] != 1 ) {
			printf ("Only boolean values [0/1] is allowed\n");
			i = i - 1;
		}	
	}
	if ( is_balanced (f, m) )
		printf ("Given function is balanced\n");
	else
		printf ("Given function is not balanced\n");
	free(f);
	return 0;
}
