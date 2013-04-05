/* Written by Giri
 * A function which computes the Walsh transform fˆ(a) 
 * of a Boolean function f (given as a truthtable) at 
 * point a ∈ F2^m . Write a function which computes 
 * fˆ(a) for all a ∈ Fm 2 (it can return an array of 
 * size 2m containing all the values)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* A function to calculate the power of a number */

// Confusing name and confusing comment:
// this function computes number * 2**(power-1)
// (where '**' represents exponentiation).
// In the context of Boolean functions,
// the term "power function" means something
// completely different
int powerFunction ( int number, int power ) {
	if ( power == 0 ) 
		return 0;
	else
		return ( number << ( power - 1 ) );
}

/* A function to invert the sign of given boolean value */

// I don't really get what this function is meant for...
// But it has the same name as a different function
// in question8.c, so it is confusing
int sign (int e) {
	return powerFunction ( (float) -1, e);
}


// Next 2 functions: what is m? there is confusion
// Try to reread the question & revise, and let's discuss if you
// don't understand.
// Also: don't do I/O in functions which should be pure!
// Do I/O in e.g. main.

void WalshTransform (int * f, int m) {
	int i;
	printf ("Walsh transform (f^(a) = Sigma (-1) ^ f(x)) of a boolean function f: \n");
	for ( i = 0; i < m; i++ ) {
		printf ("%d\n", sign(f[i]));
	}
}

void completeWalshTransform ( int * f, int * a, int m) {
	int i;
	printf ("Complete walsh transform (f^(a) = Sigma (-1)^(f(x) + a.x) of a boolean function f:\n");

	for ( i = 0; i < m; i++ ) 
		printf ("%d\n", sign (f[i] + ( a[i] * i)));
}

int main ( int argc, char ** argv ) {
	int * table_f1;
	int * a;
	int m, i, j;

	printf ("Enter the value of m: ");
	scanf ("%d", &m);

	table_f1 = ( int * ) malloc ( m * sizeof (int) );
	a =  ( int * ) malloc ( m * sizeof (int) );
	
	printf ("You are going to enter the values of the boolean function f\n");
	for ( i = 0; i < m; i++ ) {
		printf ("Enter the [%d] boolean value of boolean function f: ", i + 1);
		scanf ("%d", &table_f1[i]);

		if ( table_f1[i] > 1 )
			table_f1[i] = 1;

		if ( table_f1[i] < 0 )
			table_f1[i] = 0;
	}

	printf ("You are going to enter the values of boolean function a\n");
	for ( i = 0; i < m; i++ ) {
		printf ("Enter the [%d] boolean value of boolean function a: ", i + 1);
		scanf ("%d", &a[i]);

		if ( a[i] > 1 )
			a[i] = 1;
		if ( a[i] < 0 )
			a[i] = 0;
	}

	printf ("Truth Table\n");
	printf ("f\ta\n");

	for ( i = 0; i < m; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			if ( j == 0 ) 
				printf ("%d\t", table_f1[i]);			

			else 
				printf ("%d\n", a[i]);
		}	
	}
	WalshTransform (table_f1, m);
	completeWalshTransform (table_f1, a, m);
	return 0;
}
