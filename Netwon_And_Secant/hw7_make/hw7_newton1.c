/*stc-hw7 newton1 method*/
#include<stdio.h>
#include<math.h>
#define f(x) x*x-31
double fD(double x){
	return 2*x;
}

int main(int argc, char *argv[]){
	int i=1,kmax;
	double x0,x1,f0,epsilon,error;

	x0 = atof(argv[1]);
	epsilon = atof(argv[2]);
	kmax = atoi(argv[3]);

	f0 = f(x0);
	
	while (i <= kmax){
	
	if (fD(x0) == 0){
		printf("Method fails!");
		exit(0);
	}

	x1 = x0 - (f0/fD(x0));
	error = fabs(f(x1));

	if(error < epsilon){
		printf("Iteration %d: x=%.10f, error=%.10f\n",i,x1,error);
		break;
	}
	printf("Iteration %d: x=%.10f, error=%.10f\n",i,x1,error);
	x0 = x1;
	f0 = f(x1);
	i++;
	}

	return 0;
}
	

	
	
