/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include <stdio.h>
#include <stdlib.h>

/* A custom function to find the power of a given number */

// Again DRY. The problem is even worse as it is *almost*
// the same as powerFunction from question9.c

// In this file, you only use powerFunction with number == 2 (which computes 2**number)
// so you should simply define a function called e.g. unsigned pow2(int m)
// which returns (1u<<m);
int powerFunction ( int number, int power ) {
	if ( power == 0 )
		return 1;

	number = number << (power - 1 );
	return number;
}

/* A function which inverts the sign of the given boolean function */
// Ditto; this function seems to work, but I think powerFunction is intended
// to work with number >= 0. From the definition, I interpret
// powerFunction(-1, e) as (-1) * 2**(e-1), which does not really make sense...
// your function works for e==0 because of the special condition in powerFunction,
// and for e==1 because then powerFunction(x, e) == x for all x.
int sign (int e) {
	return powerFunction(-1, e);
}

/* A function to computer the FastWalshTransform */
// It works. Now write a pure function, which returns
// a new array containing the walsh transform
// (or better: which takes an array as a parameter where it puts
// the walsh transform values).
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
	for ( u = 0; u < powerFunction (2, m); u++ ) 
		temp_f[u] = f[u] = sign(f[u]);

	/* Prints the initial reverse sign boolean values */
	printf ("%d\t|\t", temp);
	for ( u = 0; u < powerFunction (2, m); u++ ) {
		printf ("%d\t", f[u]);

		if (u == powerFunction (2, m) - 1 )
			printf ("\n");
	}

	temp = temp - 1;
	while ( temp > -1 ) {	
            // split is then equal to powerFunction(2, temp), right??
		split = powerFunction (2, m) / ( powerFunction (2, m) / powerFunction (2, temp) );
		tempSplit = split;

		printf ("%d\t|\t", temp);	

                // this algo below, with tempSplit and count, and with
                // "% powerFunction (2, m)", seems over-complicated. There is a simpler solution.
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

	f = ( int * ) malloc ( powerFunction (2, m) * sizeof ( int ) );

	for ( i = 0; i < powerFunction (2, m); i++ ) {
		printf ("Enter the value of [%d] of boolean funciton: ", i + 1);
		scanf  ("%d", &f[i]);
	}

	FastWalshTransform (f, m);
	free (f);
	return 0;
}
