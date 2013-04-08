#ifndef HEADER_H
#define HEADER_H

/*-----------Standard header files------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*------------------Macros--------------------*/
// VERY BAD STYLE!
#define UL unsigned long
#define LL long long

// there is  a C feature designed for this purpose :
/* typedef unsigned long UL; */
// Now, "UL" is very badly chosen because it is a suffix used
// to write litteral unsigned longs, e.g.
// unsigned long x = 3UL; /* by default, '3' is an int, but 3UL is an unsigned long */
// you could use the name 'ulong' for example.
// Or better : when it represents a binary vector, you could call it
// 'bvector_t', or 'binvect' for example.


/*-----------------Functions------------------*/

// I don't remember exactly the rules for C,
// as I use C++, but I think putting function definition
// in header files is bad, at least without marking them
// as 'static' ('inline' in C++). You will have a 'multiple
// definition error' if you build a program made of 2+ object
// files including the code for these functions.
// The usual way to do is to put only declaration of these
// functions in the header file, put their definitions
// in a .c file, say "util.c", and build your programs
// with a command like 'gcc -o question1 question1.o util.o'
// However, I don't ask you to change your organisation now.

/* A function to calculate the hamming weight of a given number */
UL hamming_weight ( unsigned long u ) {
	UL count = 0;

	while ( u > 0 ) {
		if ( ( u & 1) == 1 )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

/* A function to calculate the power of 2 */
UL pow2 ( int power ) {
	if ( power == 0 )
		return 1;

	return 2 << (power - 1);
// better:
//      return 1ul << power;
// (then we don't need to handle the special case power==0
}

/* A function to invert the sign of a binary */
int sign ( UL e ) {
    // what are the valid inputs for this function?
    // If you accept any integer, maybe it will be more clear to
    // write 'if ((e % 2) == 1)' which reads more directly as
    // 'if e is in an odd number'
	if ( e & 1 )
		return -1;
	return 1;
    // If you accept only 0 and 1, directly return
    // e ? -1 : 1
    // In fact in this case there is a more efficient formula,
    // which does not need a test :
    // return 1 - 2 * e
}

//  this algo is good, but we represent binary vectors
//  as unsigned longs, not as arrays of unsigned longs
//  (this is the case only for truthtables)

/* A function to calculate the scalar product of two vectors */
UL scalar_product ( UL *table_f1, UL *table_f2, UL m ) {
	UL i, product = 0;
	for ( i = 0; i < pow2 (m); i++ ) 
		product = product + ( table_f1[i] * table_f2[i] );
	return product;
}

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
int * walsh_transform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	UL n = pow2 (m);
	UL u, j;
	UL split, tempSplit;
	temp_f = ( int * ) malloc ( n * sizeof(int) );

	for ( u = 0; u < n; u++ ) 
		temp_f[u] = f[u] = sign(f[u]);

	temp = temp - 1;
	while ( temp > -1 ) {	
		tempSplit = split = pow2 (temp) ;
		for ( u = 0; u < n; u = u + split ) {
			for ( j = u; j < u + split; j++ ) {
				if ( j < tempSplit ) 
					temp_f[j] =  f[j] + f[ ( j + split ) % n ] ; 
				else  
					temp_f[j] = f [ j - split ] - f[j]; 
			}
			count = count + 1;
			if (count == 2) {
				tempSplit = tempSplit + pow2 (split);
				count = 0;
			}
		}
		for ( u = 0; u < n; u++ )
			f[u] = temp_f[u];

		temp = temp - 1;
	}
	free (temp_f);
	return temp_f;
}
#endif
