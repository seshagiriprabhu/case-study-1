/* Written by Giri
 * Implementation of non-linearity funciton */

#include "header.h"
/* STATUS: COMPLETE */

/* A function to calculate the non-linerity of given boolean funciton  */
int nonlinearity ( int * u, ulong m ) {
	int *walshOutput;
	ulong n = 1ul << m;
	int tempMax = 0;
	ulong i;
	walshOutput = ( int * ) malloc ( n * sizeof (int) );
	walshOutput = walsh_transform(u, m);
	for ( i = 0; i < n; i++ ) {
		if ( tempMax < walshOutput[i] )
			tempMax = walshOutput[i];
	}
	return tempMax;
}

int main ( ) {
	int *u;
	ulong m, i;
	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	ulong n = 1ul << m;
	u = ( int * ) malloc ( n * sizeof (int) );
	
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu]th boolean value of boolean function: ", i);
		scanf ("%d", &u[i]);
	}
	
	printf ("Non linearity is %d\n", nonlinearity (u, m));
	free (u);
	return 0;
}

