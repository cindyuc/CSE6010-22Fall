/*
	program to take a 4-bit binary integer and return negative representations
	treat them as character strings
*/
#include <stdio.h>
#define NBITS 4
int PrintBitString(char someint[NBITS]);

int main() 
{

	// initialize
	char myint[NBITS] = "0011";

	printf("original bit string: ");
	PrintBitString(myint);

// find signmagnitude
	char signmagnitude[NBITS] = "0000";
	if(myint[0] == '0')
		signmagnitude[0] = '1';
	else
		signmagnitude[0] = '0';
	for (int j=1; j<NBITS; j++)
	{
		signmagnitude[j] = myint[j];
	}
	printf("sign magnitude bit string: ");
	PrintBitString(signmagnitude);
	
	return 0;
}

int PrintBitString(char someint[NBITS])
{
	for (int j=0; j<NBITS; j++)
		printf("%c",someint[j]);
	printf("\n");

	return 0;
}
