/* Written by Giri
   A function in m variables is said to be balanced if it takes 
   values 0 and 1 the same number of times. What is the Hamming 
   weight of such a Boolean function? Implement a function 
   is_balanced(f) which checks the balancedness of a Boolean 
   function f */

#include "header.h"


/* A function which check whether the boolean functions are balanced
 * or not */

// this function is unusable: what if I want to check the balancedness of
// millions functions? this kind of function *should never* do I/O
// (input/ouput), but return a useful value
// (boolean (true/false) value in this case).
// after all, you don't scanf the values of f and m from
// inside the function...
UL is_balanced (UL *f, UL m) {
	UL i, count = 0;

	for ( i = 0; i < pow2 (m); i++) {
		if ( f[i] == 1 )
			count = count + 1;
	}
	return count;
}

int main () {
	UL *f;
	UL m, i, count;
	printf ("Enter the value of m: ");
	scanf ("%lu", &m);
	
	if ( m == 0) {
		printf ("You must atleast give a value\n");
		exit(0);
	}

	f = ( UL * ) malloc ( m * sizeof ( UL ) );

	for ( i = 0; i < pow2 (m); i++ ) {
            // I don't think you should write 'i+1' ..
		printf ("Enter the [%lu] boolean value of the boolean function: ", i);
		scanf ("%lu", &f[i]);
		if ( f[i] != 0 && f[i] != 1 ) {
			printf ("Only boolean values [0/1] is allowed\n");
			i = i - 1;
		}	
	}

	count = is_balanced (f, m);
	if ( count == ( pow2 (m) / 2 ) )
		printf ("The given boolean function is balanced\n");
	else
		printf ("The given boolean function is not balanced\n");

	free(f)
	return 0;
}
