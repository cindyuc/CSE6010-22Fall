//gcc -o statistics_omp -fopenmp statistics_omp.c
//export OMP_NUM_THREADS=3
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){

	const int N=100;
	int x[N], i, sum, sum2;
	int upper, lower;
	int divide=20;
	sum=0;
	sum2=0;
	
	#pragma omp parallel for
	for (i=0; i<N; i++){
		x[i]=i;
	}

	#pragma omp parallel private(i) shared(x)
	{
		//fork several threads
		#pragma omp sections
		{
			{
				for(i=0; i<N; i++){
					if(x[i]>divide) upper++;
					if(x[i]<=divide) lower++;
				}
				printf("#pts <= %d in x is %d\n",divide,lower);
				printf("#pts > %d in x is %d\n",divide,upper);
			}
			#pragma omp section
			{
				//calculate the sum of x
				for (i=0; i<N; i++){
					sum=sum+x[i];
				}
				printf("sum of x = %d\n",sum);
			}
			#pragma omp section
			{
				//calculate the sum of the squares of x
				for (i=0; i<N; i++) {
					sum2=sum2+x[i]*x[i];
				}
				printf("sum of x^2 = %d\n",sum2);
			}
		}		
	}
	return 0;
}