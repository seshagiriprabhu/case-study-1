/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/
unsigned int find_indice ( unsigned int u) {
	unsigned int indice, temp;

	for ( temp = 0; temp < UINT_MAX; temp++ ) {
		if ( ( ( u >> temp) & 1 ) == 1 ) {
			indice = temp;
			break;
		}
	}
	return indice + 1;
}

int main ( int argc, char ** argv ) {
	unsigned int u;
	int choice;
	do {
		printf ("=====================================================\n");
		printf ("1. Check the position of first non-zero bit\n");
		printf ("2. Exit\n");

		printf ("Enter your choice: ");
		scanf  ("%d", &choice);

		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%du", &u);

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

