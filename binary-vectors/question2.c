/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include "header.h"

/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/
UL find_indice ( unsigned long u) {
	UL indice = 0;

	if ( u == 0 )
		return 0;
	while ( u > 0 ) {
		if ( ( u  & 1 ) == 1 ) 
			break;
		indice = indice + 1;
		u = u >> 1;
	}
	return indice;
}

int main () {
	unsigned long u;
	int choice;
	do {
		printf ("=====================================================\n");
		printf ("1. Check the position of first non-zero bit\n");
		printf ("2. Exit\n");

		printf ("Enter your choice: ");
		scanf  ("%d", &choice);

		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					if ( u > 0 )
						printf ("The indice of the first non-zero number is %lu \n", find_indice (u));
					else
						printf ("The given unsigned integer doesn't contains a non-zero value\n");
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

