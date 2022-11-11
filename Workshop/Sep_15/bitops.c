/*
	working with bit strings as character arrays
*/
#include <stdio.h>
#define NBITS 4
void PrintBitString(char* someint);
char* bitwiseAND(char* a, char* b);
char* bitwiseOR(char* a, char* b);
char* bitwiseXOR(char* a, char* b);

int main() 
{
	// initialize three bit strings as character arrays
	char myint1[NBITS] = "0101";
	char myint2[NBITS] = "1001";
	char myint3[NBITS] = "0000";

	printf("bit string 1: ");
	PrintBitString(myint1);
	
	printf("bit string 2: ");
	PrintBitString(myint2);

	printf("bit string 3: ");
	PrintBitString(myint3);

	char *myAND = bitwiseAND(myint2, myint1);
	PrintBitString(myAND);

	char *myOR = bitwiseAND(myint1, myint1);
	PrintBitString(myOR);

	char *myXOR = bitwiseAND(myint1, myint1);
	PrintBitString(myXOR);

	return 0;
}

void PrintBitString(char* someint)
{
	for (int j=0; j<NBITS; j++)
		printf("%c",someint[j]);
	printf("\n");
}

char* bitwiseAND(char* a, char* b) {
	 char *result;
	 
	 for (int i = 0; i < NBITS; i++) {
		result[i] = a[i] & b[i];
	 }
	 return result;
}

char* bitwiseOR(char* a, char* b) {
	 char *result;
	 
	 for (int i = 0; i < NBITS; i++) {
		result[i] = a[i] | b[i];
	 }
	 return result;
}

char* bitwiseXOR(char* a, char* b) {
	 char *result;
	 
	 for (int i = 0; i < NBITS; i++) {
		result[i] = a[i] ^ b[i];
	 }
	 return result;
}
