/* Written by Giri
   A function taking as inputs an integer u 
   (viewed as a binary vector) and an integer i,
   which returns the i-th bit of u	*/

#include <stdio.h>
#include <stdlib.h>

/* This function checks whether the first binary is position is 0 or 1 */
void check_first_bit ( unsigned int bit ) {
	printf ("The first bit is : %d\n", ( bit & 1 ) );
}

/* This function checks the value of the given integer's ith the binary position */
int check_random_bit ( unsigned int bit, int i ) {
	int temp = ( bit >> i ) &	1;
	return temp;
}

int main ( int argc, char ** argv ) {
	unsigned int u;
	int i, choice;
	do {
		printf ( "=====================================================\n");
		printf ( "1. Check first bit\n" );
		printf ( "2. Check a random bit\n");
		printf ( "3. Exit\n");

		printf ( "Enter your choice: ");
		scanf ("%d", &choice);


		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%du", &u);
					check_first_bit (u);
			break;

			case 2: printf ("Enter the integer: ");
					scanf ("%du", &u);
					printf ("Enter the value of ith bit which you want to extract from the integer: ");
					scanf ("%d", &i);
					printf ("The requested bit is : %d\n" , check_random_bit(u, i));
			break;

			case 3: printf ( "\n=====================================================\n");
					exit (0);
			break;

			default: printf ("Wrong choice!!\n");
			break;
		}
		printf ( "=====================================================\n");
	} while ( choice < 1 || choice > 3 );

}
