/*This is stc-hw5
* This program returns the values of biga nad bigb of F50
* Student Name: Mengjie YU
* UTEID: my3852
*/
#include<stdio.h>
#include<limits.h>

int main(){
	int biga[51];
	int bigb[51];
	/*initialize the first 2 values in biga and bigb array*/
	biga[0] = 0;
	bigb[0] = 0;
	biga[1] = 0;
	bigb[1] = 1;

	int i;
	for (i = 2; i <= 50; i++){
		if (bigb[i-1] > INT_MAX - bigb[i-2])
		{
			bigb[i] = (-1 * INT_MAX) + bigb[i-1] + bigb[i-2];
			biga[i] = biga[i-1] + biga[i-2] + 1;
		}
		else
		{
			biga[i] = biga[i-1] + biga[i-2];
			bigb[i] = bigb[i-1] + bigb[i-2];
		} 		
	}
	printf("biga for Fib(50) is %d\n",biga[50]);
	printf("bigb for Fib(50) is %d\n", bigb[50]);
	

return 0;
}
