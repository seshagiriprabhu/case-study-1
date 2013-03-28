/* Written by Giri
 * An implementation of Fast Walsh Algorithm
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void FastWalshTransform (int * f, int m ) {
	int *temp_f;
	temp_f = ( int * ) malloc ( pow(2, m) * sizeof(int) );
	int u, temp = m;

	for ( u = 0; u < pow (2, m); u++ ) {
		temp_f[u] = f[u];
	}

	int power  = pow (2, m);
	int tempPower;
	printf ("\nm\t|\t");
	for (u = 0; u < pow (2, m); u++ ) 
		printf ("%d\t", f[u]);
	printf ("\n--------------------------------------------------------------------------------\n");

	while ( temp > 0 ) {
		tempPower = pow (2, temp - 1 );		
		printf ("%d\t|\t", temp);	

		for ( u = 0; u < pow (2, m); u++ ) {

			if ( u < ( pow (2, m) / 2 ) ) { 
				printf ("\n[u]: %d, [u+tempPower]: %d, f[u]: %d, f[u+tempPower]: %d\n", u, u+tempPower, f[u], f[u + tempPower]);
				temp_f[u] =  f[u] + f[ ( u + tempPower ) ] ; 
			}

			else {
				printf ("\n[u]: %d, [u-tempPower]: %d, f[u-tempPower]: %d, F[u]: %d \n", u, u-tempPower, f[u - tempPower], f[u]);
				temp_f[u] = f [ ( u - tempPower) % power ] - f[u]; 
			}
		}

		for ( u = 0; u < pow (2, m); u++) {
			f[u] = temp_f[u];
			printf ("%d\t", f[u]);
		}

		printf ("\n");
		temp = temp - 1;
	}
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
	return 0;
}
