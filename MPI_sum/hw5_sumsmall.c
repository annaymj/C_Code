/* This is stc-hw5
* This program will return the sum of small numbers
* one sum from 1 to 10,000
* the other sum from 10,000 to 1
* Student Name: Mengjie YU
* UTEID: my3852
*/

#include<stdio.h>
#include<math.h>

float sum1 (int n){
	float total = 0.0;
	int i;
	for (i = 1; i <=n; i++){
		total += 1/pow(i,2);
		}
	return total;
	}

float sum2 (int n){
	float total = 0.0;
	int i ;
	for (i = n; i >=1; i--){
		total += 1/pow(i,2);
		}
	return total;
	}
 
int main(){
	int N = 10000;
	printf("The sum calculate from 1 to 10,000 is %3.15f\n", sum1(N));
	printf("The sum calculate from 10,000 to 1 is %3.15f\n",sum2(N));
return 0;
}
