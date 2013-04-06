/* Written by Giri
 * A function which computes the scalar product between two vectors
 * of f2^m given as integers */

#include "header.h"

int main () {
	UL *table_f1;
	UL *table_f2;
	UL i, j, m; /* M --> Number of variables in the boolean function */
	
	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);

        // here m is the number of variables... the two input vectors are of dimension m
        // which can be assumed to be < 32, and are represented by an UL
        // and we don't allocate! (which we do for truth tables of Boolean functions)
	table_f1 = ( UL * ) malloc ( pow2 (m) * sizeof (UL) );
	table_f2 = ( UL * ) malloc ( pow2 (m) * sizeof (UL) );

	for ( j = 0; j < 2; j++) {
		for ( i = 0; i < pow2 (m); i++) {
			if ( j == 0 ) {
                            // again, I think "i" is preferable to "i+1"
				printf ("Enter the [%lu] boolean value of first binary vector: ", i);
				scanf ("%lu", &table_f1[i]);
				if ( table_f1[i] != 0 && table_f1[i] != 1 ) {
					printf ("Program accepts only binary values [0/1]\n");
					i = i - 1;
				}
			}
			else {
				printf ("Enter the [%lu] boolean value of second binary vector: ", i);
				scanf ("%lu", &table_f2[i]);
				if ( table_f2[i] != 0 && table_f2[i] != 1 ) {
					printf ("Program accepts only binary values [0/1]\n");
					i = i - 1;
				}
			}
		}
	}
	
	printf ("\nTruth Table\n");
	printf ("f1\tf2\tProduct\n");

	for ( i = 0; i < pow2 (m); i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 )
				printf ("%lu\t", table_f1[i]);
			else {
				printf ("%lu\t", table_f2[i]);
				printf ("%lu\n", table_f1[i] * table_f2[i]);
			}
		}
	}

	printf ("\nThe scalar product between two binary vector is: %lu\n", scalar_product (table_f1, table_f2, m));

	free (table_f1);
	free (table_f2);
	return 0;
}
