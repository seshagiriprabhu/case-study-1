/* Written by Giri
   A function in m variables is said to be balanced if it takes 
   values 0 and 1 the same number of times. What is the Hamming 
   weight of such a Boolean function? Implement a function 
   is_balanced(f) which checks the balancedness of a Boolean 
   function f */

#include "header.h"

bool is_balanced ( ulong *f, ulong m ) {
	ulong  i, count = 0;
	for ( i = 0; i < pow2 (m); i++) 
		count = count + f[i];
	if ( count == ( pow2 (m) / 2) )
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

        // this is wrong (look at your malloc in question5), you should
        // have a function 'allocate_table(int m)' and write 'f=allocate_table(m)'
	f = ( ulong * ) malloc ( pow2 (m) * sizeof ( ulong ) );

	for ( i = 0; i < pow2 (m); i++ ) {
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
