/* Written by Giri
   A function hamming_distance(f1,f2) returning an int (the prototype in C
   would/could be int hamming_distance(int f1[], int f2[], int m) */

#include "header.h"
/* UL is the macro of unsigned long */

// comment your function: what is m?
// in the pdf, m was meant to be the number of variables,
// so we don't need to check that the input is a power of 2.
UL hamming_distance ( UL *f1, UL *f2, UL m ) {
	UL i, count = 0;
	for ( i = 0; i < pow2 (m); i++ ) {
		if ( f1[i] ^ f2[i] )
			count++;
                // same as question4: count += f1[i]^f2[i]
	}
	return count;
}

int main () {
	UL *f1;
	UL *f2;
	UL i, j, m; /* M is the number of variables in the boolean function */

	printf ("Enter the number of variables in your boolean function: ");
	scanf ("%lu", &m);

	f1 = ( UL * ) malloc ( pow2 (m) * sizeof(UL) );
	f2 = ( UL * ) malloc ( pow2 (m) * sizeof(UL) );

	for ( j = 0; j < 2; j++ ) {
		for ( i = 0; i < pow2 (m); i++ ) {
			printf ("Enter the [%lu] boolean value of [%lu] boolean table: ", i, j);
			if ( j == 0) {
				scanf ("%lu", &f1[i]);
				if ( f1[i] != 0 && f1[i] != 1 ) {
					printf ("Program accepts only boolean values[0/1]\n");
					i = i - 1;
				}
			}
			else {
				scanf ("%lu", &f2[i]);
				if ( f2[i] != 0 && f2[i] != 1 ) {
					printf ("Program accepts only boolean values[0/1]\n");
					i = i - 1;
				}
			}
		}
	}

	printf ("\nTruth Table\n");
	printf ("f1\tf2\n");

	for ( i = 0; i < pow2 (m); i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 )
				printf ("%lu\t", f1[i]);
			else 
				printf ("%lu\n", f2[i]);
		}
	}

	printf ("\nThe hamming distance of the two tables is %lu\n", hamming_distance(f1, f2, m));	
	free(f1);
	free(f2);
	return 0;
}
