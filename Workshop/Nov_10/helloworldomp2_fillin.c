//gcc -o helloworldomp2 helloworldomp2.c -fopenmp 
#include <stdio.h>
#include <omp.h>

int main(){
	int num_threads, thread_id;
	#pragma omp parallel private(num_threads,thread_id)
	{
		thread_id = FILLIN;
		printf("Hello World. This is thread %d\n",FILLIN);
		if(thread_id==0){
			num_threads = FILLIN;
			printf("Total # of threads is %d\n",FILLIN);
		}
//		#pragma omp FILLIN
		printf("...Goodbye from thread %d\n",FILLIN);
	}
return 0;
}