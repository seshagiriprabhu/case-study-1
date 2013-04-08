#ifndef HEADER_H
#define HEADER_H

/*-----------Standard header files------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*------------------Macros--------------------*/
typedef int bool;
#define true 1
#define false 0

typedef unsigned long ulong;
typedef long long llong;

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
ulong hamming_weight ( ulong u ) {
	ulong count = 0;

	while ( u > 0 ) {
		if ( ( u & 1) == 1 )
			count = count + 1;
		u = u >> 1;
	}
	return count;
}

/* A function to calculate the power of 2 */
ulong pow2 ( int power ) {
	return 1ul << power;
}

/* A function to invert the sign of a binary */
int sign ( ulong e ) {
	return 1 - 2 * e;
}

//  this algo is good, but we represent binary vectors
//  as unsigned longs, not as arrays of unsigned longs
//  (this is the case only for truthtables)

/* A function to calculate the scalar product of two vectors */
ulong scalar_product ( ulong *table_f1, ulong *table_f2, ulong m ) {
	ulong i, product = 0;
	for ( i = 0; i < pow2 (m); i++ ) 
		product = product + ( table_f1[i] * table_f2[i] );
	return product;
}

/* A function to computer the FastWalshTransform 
 * Copied from question11 */
int * walsh_transform ( int *f, int m ) {
	int *temp_f;
	int count = 0, temp = m;
	ulong n = pow2 (m);
	ulong u, j;
	ulong split, tempSplit;
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

ulong table_hamming_weight ( ulong *val, ulong m ) {
	ulong i, total_weight = 0;
	for ( i = 0; i < pow2 (m); i++ ) 
			total_weight  = total_weight + val[i];
	return total_weight;
}

#endif
