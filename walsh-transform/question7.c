/* Written by Giri
 * A function which computes the scalar product between two vectors
 * of f2^m given as integers */

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char ** argv ) {
	unsigned int * table_f1;
	unsigned int * table_f2;
	int i, j, m, product = 0;
	
	printf ("Enter the value of m: ");
	scanf ("%d", &m);

        // here m is the number of variables... the two input vectors are of dimension m
        // which can be assumed to be < 32, and are represented by an unsigned int
        // and we don't allocate! (which we do for truth tables of Boolean functions)
	table_f1 = ( unsigned int * ) malloc ( m * sizeof (unsigned int) );
	table_f2 = ( unsigned int * ) malloc ( m * sizeof (unsigned int) );

	for ( j = 0; j < 2; j++) {
		for ( i = 0; i < m; i++) {
			if ( j == 0 ) {
                            // again, I think "i" is preferable to "i+1"
				printf ("Enter the [%d] boolean value of first binary vector: ", i + 1);
				scanf ("%du", &table_f1[i]);
			}
			else {
				printf ("Enter the [%d] boolean value of second binary vector: ", i + 1);
				scanf ("%du", &table_f2[i]);
			}
		}
	}
	
	printf ("\nTruth Table\n");
	printf ("f1\tf2\tProduct\n");

	for ( i = 0; i < m; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 )
				printf ("%d\t", table_f1[i]);
			else {
				printf ("%d\t", table_f2[i]);
				printf ("%d\n", table_f1[i] * table_f2[i]);
			}
		}
	}

	for (i = 0; i < m; i++) 
		product += table_f1[i] * table_f2[i];

	printf ("\nThe scalar product between two binary vector is: %d\n", product);
        // OK, but we want a pure function here, not code in main with I/O.

	free (table_f1);
	free (table_f2);
	return 0;
}
