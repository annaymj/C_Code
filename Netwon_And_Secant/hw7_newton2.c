/*stc-hw7 newton2 method*/
#include<stdio.h>
#include<math.h>

double f( double x){
	return x/(1+pow(x,2));
	}

double fD(double x){
	double tmp1 = pow(x,2);
	double tmp2 = pow((tmp1+1),2);
	return (1-tmp1)/tmp2;
	}

int main(int argc, char *argv[]){
	int i=1,kmax;
	double x0,x1,f0,epsilon,error,fDeri;

	x0 = atof(argv[1]);
	epsilon = atof(argv[2]);
	kmax = atoi(argv[3]);
	printf("x0 is %f\n",x0);
	printf("epsilon is %f\n",epsilon);
	printf("kmax is %d\n",kmax);

	f0 = f(x0);
	printf("f0 is %f\n",f0);

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
	

	
	
