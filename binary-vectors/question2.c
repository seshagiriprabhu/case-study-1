/* Written by Giri
   A function returning the indice of the first non-zero 
   bit of a binary vector */

#include "header.h"

/* Function returns the indice of the first non-zero value
   in the given unsigned integer						*/
ulong find_indice ( ulong u) {
	ulong indice = 0;
	if ( u == 0 || u == 1)
		return 0;
	while ( u > 1 ) {
		if ( u & 1 ) 
			break;
		indice = indice + 1;
		u = u >> 1;
	}
	return indice;
        // OK now it is correct. You pretend it is much more efficient
        // in your commit message: did you measure?
        // I think it is the same performance as before,
        // _except_ for the case u==0. When u was 0, you was scanning
        // UINT_MAX bits of u before declaring it as 0!
        // Even before you was using sizeof(unsigned int)... On 32 bit machines,
        // denoting by intbits the number of bits in an int, we have:
        // 4 == sizeof(int) <= intbits == 32 <= UINT_MAX == 2**32 -1 == 4294967295
        // UINT_MAX is better than sizeof(int) as it won't give a false result,
        // but I said 'far from optimal' above because we need to test only
        // 32 == (CHAR_BIT*sizeof(unsigned int)) bits in u.
        // So your new algo is good, but as now you properly initialize
        // indice to 0, you don't need to handle the case u==0 specially.
        // And what do you think about the fact that we have :
        // find_indice(0) == find_indice(1) ?
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

