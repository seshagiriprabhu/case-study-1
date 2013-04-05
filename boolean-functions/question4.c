/* Written by Giri
   A function taking as input a truthtable (as an array 
   of ints), and returning its Hamming weight */

#include <stdio.h>
#include <stdlib.h>

/* A custom function to find the hamming weight of a passed argument */
// It is function count_non_zero from question 3! (with a better name...)
// search DRY on google/wikipedia
int hamming_weight (unsigned int u ) {
	int count = 0;
	while ( u > 0 ) {
		if ( ( u & 1 ) == 1 ) {
			count = count + 1;
		}
		u = u >> 1;
	}
	return count;
}

/* A function to calculate the hamming weight of each and every boolean value */
// better name: e.g. table_hamming_weight
int calculate_total_hamming_weight ( unsigned int * val ) {
	int i, total_weight = 0;

        // Why only 4 values?? the example in the pdf has 4 values,
        // but your function should be general (to be usable in the real world)
	for ( i = 0; i < 4; i++ ) {
            // why add hamming_weight(val[i])? what values can be in val[i]?
		total_weight += hamming_weight(val[i]);
	}
	return total_weight;
}

int main ( int argc, char ** argv ) {
	unsigned int table_f[4];
	int i;
	for ( i = 0; i < 4; i++) {
		printf ("Enter the %d(st/nd/rd/th) boolean value: ", i + 1);
		scanf ("%du", &table_f[i]);
	}
	printf ("The hamming weight of the given boolean function is : %d\n", calculate_total_hamming_weight(table_f));
	return 0;
}
