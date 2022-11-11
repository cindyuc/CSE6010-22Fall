#include <stdio.h>

int main(void)
{
	int i, j;
	int list[10];
	
	for (i = 0; i < 10; i++)
	{
		list[i] = 2*i + 3;
		for (j = 0; j <= i; j++){
			printf("%d\n", list[j]);
		}
	}

	return 0;
}