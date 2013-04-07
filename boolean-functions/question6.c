/* Written by Giri
   A function in m variables is said to be balanced if it takes 
   values 0 and 1 the same number of times. What is the Hamming 
   weight of such a Boolean function? Implement a function 
   is_balanced(f) which checks the balancedness of a Boolean 
   function f */

#include "header.h"


/* A function which check whether the boolean functions are balanced
 * or not */

// again, try to stay consistent... m was previously an int. You could have
// in header.h something like :
// typedef int num_var_t;
UL is_balanced (UL *f, UL m) {
	UL i, count = 0;

        // maybe the optimizer can do it itself, but I think
        // it is better to cache the value of pow2(m) :
	/* for ( i = 0, n=pow2(m); i < n; i++) { */
	for ( i = 0; i < pow2 (m); i++) {
            // this is exacltly the same code as in question 4.,
            // i.e. you compute the Hamming weight... DRY!
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

        // this is wrong (look at your malloc in question5), you should
        // have a function 'allocate_table(int m)' and write 'f=allocate_table(m)'
	f = ( UL * ) malloc ( m * sizeof ( UL ) );

	for ( i = 0; i < pow2 (m); i++ ) {
		printf ("Enter the [%lu] boolean value of the boolean function: ", i);
		scanf ("%lu", &f[i]);
		if ( f[i] != 0 && f[i] != 1 ) {
			printf ("Only boolean values [0/1] is allowed\n");
			i = i - 1;
		}	
	}

	count = is_balanced (f, m);
        // the test below should be in 'is_balanced', which returns 1
        // iff f is balanced, and 0 otherwise
        // (in C, 1 (or more generally any non-zero value) is true,
        // 0 is false, by convention)
	if ( count == ( pow2 (m) / 2 ) )
		printf ("The given boolean function is balanced\n");
	else
		printf ("The given boolean function is not balanced\n");

	free(f);
	return 0;
}
