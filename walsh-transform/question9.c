/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include "header.h"
/* STATUS : COMPLETE */

// I am having a question regarding the return type of this 
// function. m is an unsigned long max = (2**32) - 1
// where as -( 2**31 )  <= long <= ( 2**31 ) - 1
// long long can hold values within range 
// ( - ( 2**63 ) <= X <= ( 2**63 ) - 1
// So which data type will best fit for returning a value
// within the range - ( 2**m ) <= X <= ( 2**m )?

// I was a bit short in my comment last time.
// We don't mind the type of m, far more important is
// the type of n=1ul << m. Indeed, m could be a char,
// it just need to be able to count the number of bits in
// n (i.e. 32 or 64 typically).
// So n can represent the length of a truth table of
// upto 31 variables (1ul<<32 is undefined
// if sizeof(ulong)==4). But you are right,
// 2**31 can not be represented by a long. 
// so either use a long long, or limit your function
// to m=30 variables, with a documented precondition
// In practice, this limitation is not a problem,
// there will be other constraints (complexity of algorithms)
// which will limit (further) the number of variables of the functions
// we can study.

long WalshTransform ( ulong *f, ulong a, ulong m ) {
        assert(m <= 30);
	ulong x, product;
	long output = 0;
	ulong n = 1ul << m;

	for ( x = 0; x < n; x++ ) { 
		product = integer_product (a, x); /* Defined in utils.c*/
		output = output +  sign ( (f[x] + product) % 2 ); // '%2' like in utils.c...
	}
	return output;
}

int main () {
	ulong *table_f1;
	ulong a, m, i;

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;

	table_f1 = ( ulong * ) malloc ( n * sizeof (ulong) );
	
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu] boolean value of boolean function f: ", i);
		scanf ("%lu", &table_f1[i]);
		if ( table_f1[i] != 0 && table_f1[i] != 1 ) {
			printf ("Program accepts only binary values [0/1]\n");
			i = i - 1;
		}
	}

	printf ("Enter the value of a: ");
	scanf ("%lu", &a);

	printf ("The walsh transform of the given vector is %ld\n", WalshTransform (table_f1, a, m));
	return 0;
}
