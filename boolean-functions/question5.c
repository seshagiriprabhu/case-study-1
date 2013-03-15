/* Written by Giri
   A function hamming_distance(f1,f2) returning an int (the prototype in C
   would/could be int hamming_distance(int f1[], int f2[], int m) */

#include <stdio.h>
#include <stdlib.h>

int hamming_distance ( unsigned int * f1, unsigned int * f2, int m ) {
	int i, count = 0;
	for ( i = 0; i < m; i++ ) {
		if ( f1[i] ^ f2[i] )
			count++;
	}
	return count;
}

int main ( int argc, char ** argv ) {
	unsigned int * f1;
	unsigned int * f2;
	int i, j, m;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	f1 = ( unsigned int * ) malloc ( m * sizeof(unsigned int) );
	f2 = ( unsigned int * ) malloc ( m * sizeof(unsigned int) );

	for ( j = 0; j < 2; j++ ) {
		for ( i = 0; i < m; i++ ) {
				printf ("Enter the %d(st/nd/rd/th) boolean value of %d(st/nd/rd/th) boolean table: ", i + 1, j + 1);
			if ( j == 0)
				scanf ("%du", &f1[i]);
			else 
				scanf ("%du", &f2[i]);
		}
	}

	printf ("\nTruth Table\n");
	printf ("f1\tf2\n");

	for ( i = 0; i < m; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 )
				printf ("%d\t", f1[i]);
			else 
				printf ("%d\n", f2[i]);
		}
	}

	printf ("\nThe hamming distance of the two tables is %d\n", hamming_distance(f1, f2, m));	
	free(f1);
	free(f2);
	return 0;
}
