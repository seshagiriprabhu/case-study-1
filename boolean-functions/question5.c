/* Written by Giri
   A function hamming_distance(f1,f2) returning an int (the prototype in C
   would/could be int hamming_distance(int f1[], int f2[], int m) */

#include "header.h"
/* STATUS: COMPLETE */

ulong hamming_distance ( ulong *f1, ulong *f2, ulong m ) {
	ulong i, count = 0;
	ulong n = 1ul << m;
	for ( i = 0; i < n; i++ )
		count = count + ( f1[i]^f2[i] );
	return count;
}

int main () {
	ulong *f1;
	ulong *f2;
	ulong i, j, m; /* M is the number of variables in the boolean function */

	printf ("Enter the number of variables in your boolean function: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;
	f1 = ( ulong * ) malloc ( n * sizeof ( ulong ) );
	f2 = ( ulong * ) malloc ( n * sizeof ( ulong ) );

	for ( j = 0; j < 2; j++ ) {
		for ( i = 0; i < n; i++ ) {
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

	for ( i = 0; i < n; i++ ) {
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
