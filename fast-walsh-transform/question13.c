/* Written by Giri
 * Implementation of non-linearity funciton */

#include "header.h"
/* STATUS: COMPLETE */

/* A function to calculate the non-linerity of given boolean funciton  */
long nonlinearity ( long *u, ulong m ) {
	long *walshOutput;
	ulong n = 1UL << m;
	ulong i;
	walshOutput = allocate_long_table (m);
	walshOutput = walsh_transform(u, m);
	long tempMax = walshOutput[0];;
	for ( i = 0; i < n; i++ ) {
		if ( tempMax < walshOutput[i] )
			tempMax = walshOutput[i];
	}
	return tempMax;
}

int main ( ) {
	long *u;
	ulong m, i;
	printf ("Enter the number of variables in the boolean function: ");
	scanf ("%lu", &m);
	assert (m <= 30);
	ulong n = 1UL << m;
	u = allocate_long_table (m);
	
	for ( i = 0; i < n; i++ ) {
		printf ("Enter the [%lu]th boolean value of boolean function: ", i);
		scanf ("%ld", &u[i]);
		if ( u[i] != 0 && u[i] != 1)
			i = i - 1;
	}
	
	printf ("Non linearity is %ld\n", nonlinearity (u, m));
	free (u);
	return 0;
}

