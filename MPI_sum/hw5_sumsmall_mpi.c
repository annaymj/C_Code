/*********************************************
*   DESCRIPTION:
*   Parallel calculating sum for (1/N^2) from 1 to N
*   and N to 1  for STC HW5
*   Student Name: Mengjie Yu
***********************************************/

#include <stdio.h>
#include <mpi.h>
#include <math.h>

const int NNN=1000000;

float get_sum1 (int n_start, int n_end){
        float total = 0.0;
        int i;
        for (i = n_start ; i <=n_end; i++){
                total += 1/pow(i,2);
                }
        return total;
        }

int get_localend(int n, int rank, int size){
	if (rank == size-1)
		return n;
	return (rank +1) * (NNN/size);
}

int main(int argc, char *argv[])
{
        int myrank, size;
	int localstart, localend;
	double localsum=0.0,sum=0.0;
	// Initilize Mpi and local rank and size
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if(myrank==0)
                printf("This is the parallel(MPI) calculateSum program in C.\n");
	
	//Different MPI Tasks are doing different jobs!!!
        localstart=NNN/size * myrank+1; 
	localend = get_localend(NNN,myrank,size);
	/*localend=NNN/size * (myrank +1);*/
	localsum = get_sum1(localstart,localend);

        printf("The subsum of sum1: %2d of %2d: sum from %4d to %4d is %3.15f \n", myrank, size, localstart, localend, localsum );

	
	MPI_Reduce(&localsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(myrank==0)
		printf("\nThe value of sum1 is: %3.15f\n", sum );

        MPI_Finalize();
        return 0;
}
