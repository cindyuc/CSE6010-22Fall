//gcc -o reduce_omp2 -fopenmp reduce_omp2.c -lm
#include <stdio.h>
#include <math.h>
#include <omp.h>
#define NVALS 10000

int main(){
	int i, chunk;
	float a[NVALS], result;
	chunk = 10;
	result = 0.0; // not the safest initialization value, but can reasonably expect some positive values
	
	for (i=0; i<NVALS; i++){
		a[i] = i*1.0;
	}

	#pragma omp parallel for default(shared) private(FILLIN) schedule(static, chunk)\
	  reduction(FILLIN : FILLIN)
	  for (i=0; i<NVALS; i++) {
		  if ( FILLIN )
			result = FILLIN);
	  }
	  
	printf("result = %.10f\n",result);
	return 0;
}