/* Written by Giri
   A function that implements the Hamming  weight of a binary 
   vector 
   In this example, I have used a built in function called 
   int __builtin_popcount (unsigned int x), which will return 
   the number of non-zero values in the given unsigned int */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int count_non_zero ( unsigned int u ) {
	unsigned int count = 0;

	while ( u > 0 ) {
		count = count + 1;
		u = u & ( u - 1 );
	}

	return count;
}

int main ( int argc, char ** argv ) {
	unsigned int u;
	int choice;
	do {
		printf ( "==========================================\n");
		printf ("1. Find the Hamming weight of a binary vector (using built in function): \n");
		printf ("2. Find the Hamming weight of a binary vector (using a custom function): \n");
		printf ("3. Exit\n");
		printf ("Enter your choice: ");
		scanf ("%d", &choice);
		switch ( choice ) {
			case 1: printf ("Enter the binary vector: ");
					scanf ("%du", &u);
					printf ("The Number of 1s in your binary vector is : %d\n", __builtin_popcount(u));
			break;
			
			case 2: printf ("Enter the binary vector: ");
					scanf ("%du", &u);

					if ( u == 0 )
						printf ("There isn't any non-zero values in your binary vector\n");
					else
						printf ("The Number of 1s in your binary vector is : %d\n", count_non_zero(u));
			break;

			case 3: printf ( "==========================================\n");
					exit(0);
			break;

			default:
			break;
		}
		printf ( "==========================================\n");
	} while ( ! ( choice < 1 || choice > 2 ) );
	return  0;
}
