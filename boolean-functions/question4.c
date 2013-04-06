/* Written by Giri
   A function taking as input a truthtable (as an array 
   of ints), and returning its Hamming weight */

#include "../header/header.h" /* FIX THIS make it to #include<header.h> */

/* A custom function to find the hamming weight of a passed argument */
// It is function count_non_zero from question 3! (with a better name...)
// search DRY on google/wikipedia

/* A function to calculate the hamming weight of each and every boolean value */
// better name: e.g. table_hamming_weight
int table_hamming_weight ( unsigned long * val, int m ) {
	int i, total_weight = 0;

        // Why only 4 values?? the example in the pdf has 4 values,
        // but your function should be general (to be usable in the real world)
	for ( i = 0; i < pow2 (m); i++ ) {
            // why add hamming_weight(val[i])? what values can be in val[i]?
		if ( val[i] == 1 )
			total_weight  = total_weight + 1;
	}
	return total_weight;
}

int main ( int argc, char ** argv ) {
	unsigned long * table_f;
	int i;
	int m; /* Number of variables in the boolean function */

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%d", &m);
	
	table_f = ( unsigned long * ) malloc ( pow2 (m) * sizeof ( unsigned long *) );

	for ( i = 0; i < pow2 (m); i++) {
		printf ("Enter the %d(st/nd/rd/th) boolean value: ", i + 1);
		scanf ("%lu", &table_f[i]);
	}
	printf ("The hamming weight of the given boolean function is : %d\n", table_hamming_weight(table_f, m));
	return 0;
}
