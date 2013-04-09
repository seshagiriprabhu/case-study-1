/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include "header.h"
/* Status: Complete */
/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/
ulong find_indice ( ulong u) {
	ulong indice = 0;
        // this version does the same thing as before
        // The next two lines (special case for 0 and 1) are not useful:
        // check that the result is the same if you remove them
	if ( u == 0 || u == 1)
		return 0;
	while ( u > 1 ) { // you changed 0 for 1... but you break the
                          // loop if 'u&1', so the result is exactly the same
                          // you could have written 'while (true)'
		if ( u & 1 ) 
			break;
		indice = indice + 1;
		u = u >> 1;
	}
	return indice;
}

// my question was:
       // And what do you think about the fact that we have :
       // find_indice(0) == find_indice(1) ?
// Answer: not a good idea! so we need to give a special value
// to find_indice(0). Intuitively it would be +infinity, agreed?


// To represent it, we set it to ULONG_MAX. This value has the nice
// property that ULONG_MAX+1UL == 0. So I propose the following function,
// do check that it works (is it an optimal solution?) :

ulong proposed_find_indice(ulong u) {
    if (u == 0UL)
        return ULONG_MAX;
    ulong indice = 0;
    for (; !(u & 1UL); u >>= 1)
            ++indice;
    return indice;
}

int main () {
	ulong u;
	ulong choice;
	do {
		printf ("=====================================================\n");
		printf ("1. Check the position of first non-zero bit\n");
		printf ("2. Exit\n");

		printf ("Enter your choice: ");
		scanf  ("%lu", &choice);

		switch ( choice ) {
			case 1: printf ("Enter the integer: ");
					scanf ("%lu", &u);
					printf ("The indice of the first non-zero number is %lu \n", find_indice (u));
			break;
			
			case 2: printf ("\n=====================================================\n");
					exit (0);
			break;

			default: printf ("00ps! Wrong choice!\n");
			break;
		}
	} while ( ! ( choice < 1 || choice > 2 ) );

	printf ("=====================================================\n");
	return 0;
}

