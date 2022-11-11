// bank program to introduce structures
#include <stdio.h>
#define FUNDLEN 50

typedef struct bank {
	char bankName[FUNDLEN];
	int zipCode;
	int bankID;
} Bank;

struct customer {
	Bank bankInfo;
	int customerID;
	double savingsBalance;
	double checkingBalance;
};

// can use const for these functions because values will not change
double TotalBalance(const struct customer * acctPtr); // argument is a pointer
double SavingsShare(const struct customer patron); // argument is a structure
void PrintBankInfo(const Bank bankhere); //argument is a structure

int main(void) 
{
	Bank gtbank = {
		"Georgia Tech Bank",
		30000,
		8810
	};
	
	struct customer Anna = {
		gtbank,
		12345,
		2593.53,
		842.15
	};

	printf("Anna's customerID is %d.\n",Anna.customerID);
	printf("Anna has a total of $%.2f.\n",TotalBalance(&Anna));
	printf("%.1f percent of her total is in savings.\n",SavingsShare(Anna));
	printf("Her bank's ID is %d.\n",Anna.bankInfo.bankID); 
	PrintBankInfo(Anna.bankInfo);
	
}

double TotalBalance(const struct customer * acctPtr) 
{
	// use -> notation because acct is a pointer; this allows access to the field
	return (acctPtr->savingsBalance + acctPtr->checkingBalance);
}

double SavingsShare(const struct customer patron) // argument is a structure
{
	return (100.0 * patron.savingsBalance / (patron.savingsBalance+patron.checkingBalance) );
}

void PrintBankInfo(const Bank bankhere) //argument is a structure
{
	printf("Her bank's name is %s.\n",bankhere.bankName);
}