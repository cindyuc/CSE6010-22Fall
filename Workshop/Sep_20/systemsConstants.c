/* 
	Accessing some system constants
*/ 
#include <stdio.h>
#include <limits.h>

int main() 
{
	// the maximum value for an int
	printf("Maximum integer is %d\n",INT_MAX);
	// the minimum value for an int
	printf("Minimum integer is %d\n",INT_MIN);
	// the number of bits in a byte.
	printf("Number of bits in a char is %d\n",CHAR_BIT);
	// the maximum value for an unsigned int.
	printf("Maximum unsigned integer is %d\n", UINT_MAX);
	// the minimum value for a long int.
	printf("Minimum long integer is %ld\n", LONG_MIN);
	// the maximum value for a long int.
	printf("Maximum long integer is %ld\n", LONG_MAX);
	// the minimum value for a short int.
	printf("Minimum shor integer is %d\n", SHRT_MIN);
}
