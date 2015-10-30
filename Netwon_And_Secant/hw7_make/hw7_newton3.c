/*stc-hw7 newton3 method*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define JM(i,j) jm[(i) + (j) * n]
void dgesv_();

double get_error(double x, double y, double z){
	double f0 = pow(x,2) + pow (y,2) + pow (z,2) -3; 
	double f1 = 3*x + 2 * y + 4*z -9;
	double f2 = x*y + x*z -2*y*z;
	return sqrt(pow(f0,2) + pow(f1,2) + pow(f2,2));
	}

int main(int argc, char *argv[]){
	int i,j,k=1,kmax,n=3,one=1,info;
	float x0,y0,z0,epsilon,error;
	double *f=malloc(n*sizeof(double));
	double *jm=malloc(n*n*sizeof(double));
	int *ipiv=malloc(n*sizeof(int));


	x0 = atof(argv[1]);
	y0 = atof(argv[2]);
	z0 = atof(argv[3]);
	epsilon = atof(argv[4]);
	kmax = atoi(argv[5]);
	printf("x0 is %f\n",x0);
	printf("y0 is %f\n",y0);
	printf("z0 is %f\n",z0);
	printf("epsilon is %f\n",epsilon);
	printf("kmax is %d\n",kmax);

	while (k <= kmax){
	
	/*create matrix F(i,j)*/
	f[0] = (pow(x0,2) + pow(y0,2) +pow(z0,2) -3) *(-1);
	f[1] = (3*x0 + 2*y0 + 4*z0 -9) * (-1);
	f[2] = (x0*y0 + x0*z0 - 2*y0*z0) *(-1);

	/*create Jacobian matrix J(i,j)*/
	JM(0,0) = 2*x0;		JM(0,1) = 2*y0; 		JM(0,2) = 2*z0;
	JM(1,0) = 3; 		JM(1,1) = 2; 			JM(1,2) = 4;
	JM(2,0) = y0+z0;	JM(2,1) = x0-2*z0;		JM(2,2) = x0-2*y0;

	dgesv_(&n,&one,jm,&n,ipiv,f,&n,&info);
	
	x0 += f[0];
	y0 += f[1];
	z0 += f[2];

	error = get_error(x0,y0,z0);
	if(error < epsilon){
		printf("Iteration %d: solution= (%.6f, %.6f, %.6f), error=%.10f\n",k,x0,y0,z0,error);
		break;
	}	printf("Iteration %d: solution= (%.6f, %.6f, %.6f), error=%.10f\n",k,x0,y0,z0,error);
	k++;
	}

	return 0;
}
	

	
	
