/* Written by Giri
 * For e ∈ F2, (−1)e is the sign function, with 
 * (−1)0 = 1 and (−1)1 = −1. Implement this
 * function (int sign(int e) in C) */

#include "header.h"
/* STATUS : COMPLETE */

int main () {
	int value;
	printf ("Enter the value: ");
	scanf ("%d", &value);

	if ( value != 0 && value != 1 ) {
		printf ("Program accepts only binary values [0/1]\n");
		exit(0);
	}

	printf ("The sign(%d), is : %d\n", value, sign(value)); /* sign function is defined in header.h */
	return 0;
}
