//gcc -o addarrays_omp4 -fopenmp addarrays_omp4.c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){

	const int N = 60;
	int nthreads,threadid,i;
	double a[N], b[N], result[N];
	
	//initialize
	for (i=0; i<N; i++){
		a[i]=1.0*i;
		b[i]=2.0*i;
	}
	
	int chunk=4; //distribute in chunks; assign early threads extra bits

	#pragma omp parallel private(threadid)
	{ //fork
		threadid=omp_get_thread_num();
		
		#pragma omp for schedule(static,chunk)
		for (i=0; i<N; i++){
			result[i]=a[i]+b[i];
			printf("Thread id %d working on index %d\n",threadid,i);
		}
	}  //join
	
	printf("test result[59]=%g\n",result[59]);
	
	return 0;
}