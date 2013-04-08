/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include "header.h"
/* Status: Complete */
/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/
ulong find_indice ( ulong u) {
	ulong indice = 0;
	if ( u == 0 || u == 1)
		return 0;
	while ( u > 1 ) {
		if ( u & 1 ) 
			break;
		indice = indice + 1;
		u = u >> 1;
	}
	return indice;
}

int main () {
	ulong u;
	ulong choice;
	do {
		printf ("=====================================================\n");
		printf ("1. Check the position of first non-zero bit\n");
		printf ("2. Exit\n");

		printf ("Enter your choice: ");
		scanf  ("%lu", &choice);

		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					printf ("The indice of the first non-zero number is %lu \n", find_indice (u));
			break;
			
			case 2: printf ("\n=====================================================\n");
					exit (0);
			break;

			default: printf ("00ps! Wrong choice!\n");
			break;
		}
	} while ( ! ( choice < 1 || choice > 2 ) );

	printf ("=====================================================\n");
	return 0;
}

