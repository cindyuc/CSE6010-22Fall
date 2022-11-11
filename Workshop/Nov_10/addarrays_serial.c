#include <stdio.h>
#include <stdlib.h>

int main() 
{
	const int N = 60;
	int i;
	double a[N], b[N], result[N];
	
	//initialize
	for (i=0; i<N; i++){
		a[i]=1.0*i;
		b[i]=2.0*i;
	}
	
	for (i=0; i<N; i++){
		result[i]=a[i]+b[i];
	}
	
	printf("test result[59]=%g\n",result[59]);
	
	return 0;
}