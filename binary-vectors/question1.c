/* Written by Giri
   A function taking as inputs an integer u (viewed as a binary vector)
   and an integer i, which returns the i-th bit of u */

#include "header.h"
/* STATUS : COMPLETE */
/* Functions are defined in util.c */

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
					printf ("The first bit is %d\n", check_first_bit (u));
			break;

			case 2: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					printf ("Enter the value of ith bit which you want to extract from the integer: ");
					scanf ("%lu", &i);
					printf ("The requested bit is : %d\n" , check_random_bit(u, i));
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
