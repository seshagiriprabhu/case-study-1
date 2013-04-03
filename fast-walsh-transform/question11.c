/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* A custom function to find the power of a given number */
int powerFunction ( int number, int power ) {
	if ( power == 0 )
		return 1;

	number = number << (power - 1 );
	return number;
}

/* A function to computer the FastWalshTransform */
void FastWalshTransform ( int * f, int m ) {
	int * temp_f;
	temp_f = ( int * ) malloc ( powerFunction (2, m) * sizeof(int) );
	int u, j, temp = m, count = 0;
	int split, tempSplit;
	
	/* Prints the actual boolean values as index */
	printf ("\nm\t|\t");
	for (u = 0; u < powerFunction (2, m); u++ ) 
		printf ("%d\t", f[u]);
	printf ("\n--------------------------------------------------------------------------------\n");
	
	/* Replaces all the values of the function by their sign */
	for ( u = 0; u < powerFunction (2, m); u++ ) {

		if ( f[u] == 0 ) 
			f[u] = 1;
	
		else 
			f[u] = -1;

		temp_f[u] = f[u];
	}

	/* Prints the initial reverse sign boolean values */
	printf ("%d\t|\t", temp);
	for ( u = 0; u < powerFunction (2, m); u++ ) {
		printf ("%d\t", f[u]);

		if (u == powerFunction (2, m) - 1 )
			printf ("\n");
	}

	temp = temp - 1;
	while ( temp > -1 ) {	
		split = powerFunction (2, m) / ( powerFunction (2, m) / powerFunction (2, temp) );
		tempSplit = split;

		printf ("%d\t|\t", temp);	

		for ( u = 0; u < powerFunction (2, m); u = u + split ) {
			for ( j = u; j < u + split; j++ ) {

				/* if the current  index is less than the split value, it adds the boolean values */
				if ( j < tempSplit ) 
					temp_f[j] =  f[j] + f[ ( j + split ) % powerFunction (2, m) ] ; 

				/* if the current index is greater than the split value, it takes the difference 
				 * of the boolean values */
				else 
					temp_f[j] = f [ j - split ] - f[j]; 
			}

			/* Re-assigns the temp split value after two iterations 
			 * i.e after completing one round of addition operations (f[u] + f[u + split ]
			 * and difference operation (f[u] - f[u - split]) */
			count = count + 1;

			if (count == 2) {
				tempSplit = tempSplit + powerFunction (2, split);
				count = 0;
			}
		}
		
		/* Prints the boolean values at each stages */
		for ( u = 0; u < powerFunction (2, m); u++ ) {
			f[u] = temp_f[u];
			printf ("%d\t", f[u]);

			if ( u == ( powerFunction (2, m) - 1 ) )
				printf ("\n");
		}

		temp = temp - 1;
	}
	free (temp_f);
}

int main ( int argc, char ** argv ) {
	int * f;
	int m, i;

	printf ("Enter the value of m : ");
	scanf ("%d", &m);

	f = ( int * ) malloc ( pow (2, m) * sizeof ( int ) );

	for ( i = 0; i < pow(2, m); i++ ) {
		printf ("Enter the value of [%d] of boolean funciton: ", i + 1);
		scanf  ("%d", &f[i]);
	}
	FastWalshTransform (f, m);
	free (f);
	return 0;
}
