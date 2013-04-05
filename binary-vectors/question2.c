/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/

// why not use type "unsigned long"?
// I guess it is of same size on your machine.
// On 64-bit architectures, (unsigned) int is usually 32 bits
// whereas (unsigned) long is 64 bits (native ints), so
// long is preferred.

int find_indice ( unsigned long u) {
	int indice = 0;

	if ( u == 0 )
		return 0;

    // why do you choose the name 'temp'?	
    // UINT_MAX is an improvement over previous version, but it is far
    // from optimal! (maybe it is even UB (undefined behaviour) - even if
    // I think it is defined for gcc - when shifting u for u == 0
	while ( u > 0 ) {
		if ( ( u  & 1 ) == 1 ) 
			break;

		indice = indice + 1;
		u = u >> 1;
	}
        // I think you should return indice, the user knows that indices
        // start at 0.
        // what is the value of indice for u == 0??
	return indice;
}

int main ( int argc, char **argv ) {
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
						printf ("The indice of the first non-zero number is %d \n", find_indice (u));

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

