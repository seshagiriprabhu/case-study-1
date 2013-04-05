/* Written by Giri
 * For e ∈ F2, (−1)e is the sign function, with 
 * (−1)0 = 1 and (−1)1 = −1. Implement this
 * function (int sign(int e) in C) */

#include <math.h>
#include <stdio.h>

int sign (int e) {	
    // we don't want to use pow here (which BTW uses double (not int)),
    // it is overkill for such a simple function.
    // An OK solution:
    // return e ? (-1) : 1;
    // But it involves a conditional test, which is inefficient.
    // There is another solution based only on integer arithmetic.
	return pow ( (float) -1, e);
}

int main ( int argc, char ** argv ) {
	int value;
	printf ("Enter the value: ");
	scanf ("%d", &value);
	printf ("The sign(%d), is : %d\n", value, sign(value));
	return 0;
}
