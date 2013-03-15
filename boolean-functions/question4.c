/* Written by Giri
   A function taking as input a truthtable (as an array 
   of ints), and returning its Hamming weight */

#include <stdio.h>
#include <stdlib.h>

int calculate_total_hamming_weight ( unsigned int * val ) {
	int i, total_weight = 0;

	for ( i = 0; i < 4; i++ ) {
		total_weight += __builtin_popcount(val[i]);
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
