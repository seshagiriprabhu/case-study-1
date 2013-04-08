/* Written by Giri
   A function taking as inputs an integer u (viewed as a binary vector)
   and an integer i, which returns the i-th bit of u */

#include "header.h"

/* This function checks whether the first binary is position is 0 or 1 */
bool check_first_bit ( ulong bit ) {
	return ( bit & 1 );
}

/* This function checks the value of the given integer's ith the binary 
   position */
ulong check_random_bit ( ulong bit,  ulong i ) {
	return ( ( bit >> i ) & 1 );
// try to be consistent : temp is int but bit is unsigned int.
// And now you are using unsigned longs almost everywhere...
// We prefer in general not mixing types in arithmetic. At best,
// it (may) incur a cast penalty.
}

int main () {
	ulong u, i, choice;
	do {
		printf ("=====================================================\n");
		printf ("1. Check first bit\n");
		printf ("2. Check a random bit\n");
		printf ("3. Exit\n");

		printf ("Enter your choice: ");
		scanf  ("%lu", &choice);

		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					if ( check_first_bit (u) )
						printf ("First bit is 1\n");
					else
						printf ("First bit is 0\n");
			break;

			case 2: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					printf ("Enter the value of ith bit which you want to extract from the integer: ");
					scanf ("%lu", &i);
					printf ("The requested bit is : %lu\n" , check_random_bit(u, i));
			break;

			case 3: printf ("\n=====================================================\n");
					exit (0);
			break;

			default: printf ("00ps! Wrong choice!!\n");
			break;
		}
		printf ( "=====================================================\n");
	} while ( ! ( choice < 1 || choice > 3 ) );
	return 0;
}
