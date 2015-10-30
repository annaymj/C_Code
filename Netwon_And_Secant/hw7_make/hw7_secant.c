/*stc-hw7 secant method*/
#include<stdio.h>
#include<math.h>
#define f(x) x*x-576

int main(int argc, char *argv[]){
	int i=2,kmax;
	double x0,x1,f0,f1,epsilon,x2,error;

	x0 = atof(argv[1]);
	x1 = atof(argv[2]);
	epsilon = atof(argv[3]);
	kmax = atoi(argv[4]);
	
	f0 = f(x0);
	f1 = f(x1);
	while (i <= kmax){
	
	if((f1-f0) == 0){
		printf("Method fails");
		exit(0);
	}

	x2 = x1 - (f1 *(x1-x0)/(f1-f0));
	error = fabs(f(x2));
	if(error < epsilon){
		printf("Iteration %d: x=%.10f, error=%.10f\n",i,x2,error);
		break;
	}
	printf("Iteration %d: x=%.10f, error=%.10f\n",i,x2,error);
	x0 = x1;
	f0 = f1;
	x1 = x2;
	f1 = f(x2);
	i++;
	}

	return 0;
}
	

	
	
