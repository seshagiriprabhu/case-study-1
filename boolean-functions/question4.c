/* Written by Giri
   A function taking as input a truthtable (as an array 
   of ints), and returning its Hamming weight */

#include "header.h"
/* STATUS: COMPLETE */

int main ( ) {
	ulong *table_f;
	ulong i;
	ulong m; /* Number of variables in the boolean function */

	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
        // I said that you need to write a function allocate_table!
        // this line is wrong (I didn't notice the error last time)
	table_f = ( ulong * ) malloc ( pow2 (m) * sizeof ( ulong *) );

	for ( i = 0; i < pow2 (m); i++) {
		printf ("Enter the [%lu] boolean value: ", i);
		scanf ("%lu", &table_f[i]);
		if ( table_f[i] != 0 && table_f[i] != 1 ) { 
			printf ("Program accepts only boolean values [0/1]\n");
			i = i - 1;
		}
	}

	printf ("The hamming weight of the given boolean function is : %lu\n", table_hamming_weight(table_f, m));
	free(table_f);
	return 0;
}
