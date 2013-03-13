/* Written by Giri
   A function that implements the Hamming  weight of a binary 
   vector 
   In this example, I have used a built in function called 
   int __builtin_popcount (unsigned int x), which will return 
   the number of non-zero values in the given unsigned int */

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char ** argv ) {
	unsigned int u;
	int choice;
	do {
		printf ( "==========================================\n");
		printf ("1. Find the Hamming weight of a binary vector: \n");
		printf ("2. Exit\n");
		printf ("Enter your choice: ");
		scanf ("%d", &choice);
		switch ( choice ) {
			case 1: printf ("Enter the binary vector: ");
					scanf ("%du", &u);
					printf ("Number of 1s in your binary vector is : %d\n", __builtin_popcount(u));
			break;
			
			case 2: printf ( "==========================================\n");
					exit(0);
			break;

			default:
			break;
		}
		printf ( "==========================================\n");
	} while ( choice < 1 || choice > 2 );
}
