/* Written by Giri
   A function taking as input a truthtable (as an array 
   of ints), and returning its Hamming weight */

#include "header.h"
/* UL is the macro of unsigned long */
/* A custom function to find the hamming weight of a passed argument */
// It is function count_non_zero from question 3! (with a better name...)
// search DRY on google/wikipedia

/* A function to calculate the hamming weight of each and every boolean value */
// better name: e.g. table_hamming_weight
UL table_hamming_weight ( UL * val, int m ) {
	UL i, total_weight = 0;

        // Why only 4 values?? the example in the pdf has 4 values,
        // but your function shoULd be general (to be usable in the real world)
	for ( i = 0; i < pow2 (m); i++ ) {
            // why add hamming_weight(val[i])? what values can be in val[i]?
		if ( val[i] == 1 )
			total_weight  = total_weight + 1;
	}
	return total_weight;
}

int main ( ) {
	UL * table_f;
	UL i;
	UL m; /* Number of variables in the boolean function */

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	
	table_f = ( UL * ) malloc ( pow2 (m) * sizeof ( UL *) );

	for ( i = 0; i < pow2 (m); i++) {
		printf ("Enter the %lu(st/nd/rd/th) boolean value: ", i + 1);
		scanf ("%lu", &table_f[i]);
	}

	printf ("The hamming weight of the given boolean function is : %lu\n", table_hamming_weight(table_f, m));
	return 0;
}
