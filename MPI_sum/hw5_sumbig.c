/* This is stc-hw5 
* This program returns the values of biga and bigb representing
* the summation of the 50,000 numbers read from a file
* Student Name: Mengjie YU
* UTEID: my3852
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
	FILE *file;
	char *mode = "r";
	int biga = 0;
	int bigb = 0;

	file = fopen("datafile",mode);
	if (file == NULL){
		fprintf(stderr, "Can't open input file in.txt!\n");
		exit(1);
	}
	else{
		int num;
		fscanf(file,"%d",&num);
		while (!feof (file)){
			if ( bigb > INT_MAX - num){
				biga += 1;
				bigb = (-1)*INT_MAX +bigb + num;
			}
			else{
				bigb += num;
			}
			fscanf(file,"%d",&num);
		}
	}
	fclose(file);
	printf("biga is %d\n", biga);
	printf("bigb is %d\n", bigb);

return 0;
}
