/* Written by Giri
   A function in m variables is said to be balanced if it takes 
   values 0 and 1 the same number of times. What is the Hamming 
   weight of such a Boolean function? Implement a function 
   is_balanced(f) which checks the balancedness of a Boolean 
   function f */

#include <stdio.h>
#include <stdlib.h>

/* A function to calculate the hamming weight */
int hamming_weight (unsigned value) {
	int count = 0;

	while ( value > 0 ) {
		if ( ( value & 1 ) == 1 ) 
			count = count + 1;
		value = value >> 1;
	}

	return count;
}

/* A function which check whether the boolean functions are balanced
 * or not */
void is_balanced (unsigned int * f, int m) {
	int i, count = 0;

	for ( i = 0; i < m; i++) {
		count += hamming_weight (f[i]);
	}

	if ( count != ( m / 2 ) )
		printf ("The given boolean function is not balanced\n");

	else
		printf ("The given boolean function is balanced\n");
}

int main ( int argc, char ** argv ) {
	unsigned int * f;
	int m, i;
	printf ("Enter the value of m: ");
	scanf ("%d", &m);
	
	if ( m == 0) {
		printf ("You must atleast give a value\n");
		exit(0);
	}

	f = ( unsigned int * ) malloc ( m * sizeof ( unsigned int ) );


	for ( i = 0; i < m; i++ ) {
		printf ("Enter the value of bool[%d]: ", i + 1);
		scanf ("%du", &f[i]);
	}

	is_balanced (f, m);

	return 0;
}
