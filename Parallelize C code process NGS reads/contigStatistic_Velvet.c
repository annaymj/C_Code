/*This is the contigStatistic script for Velvet output 
Last Modifed: 11/30/14
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000000

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);


int main(int argc, char *argv[]){
	FILE *inFile;
	FILE *outFile;
	char *inMode = "r";
	char *outMode = "w";
	char line[900];
	const char s[2]="_";
	int contig[2000000];
	int total_len = 0;
	int N50=0,k,sub_total_len = 0;
	int n = 0;
	if (argc != 3){
		printf("usage: %s input_file output_file\n", argv[0]);
	}

	inFile = fopen(argv[1],inMode);
	outFile = fopen(argv[2],outMode);
	
	if(inFile == NULL){
		fprintf(stderr, "Cannot open input file");
		exit(1);
	}
	else {
		while (fgets(line,sizeof(line),inFile) != NULL){
			if(line[0] == '>'){
				char *token;
				char id[900];
				int i =1;
				strcpy(id,line);
				token  = strtok(id,s);
				
				while(token != NULL && i<4){
					token = strtok(NULL,s);
					i++;
				}
				contig[n] = atoi(token);
				total_len += atoi(token);
				strncat(token,"\n",100);				
				fprintf(outFile,token);
				n++;
			}
		}
			
	}
	partition(contig,0,n-1);

	//calculate N50: the length of the collection of contigs of that length or longer contains at least half of the sum of the total length
	for(k = n-1; k>=0; k--){
		sub_total_len += contig[k];
		if (sub_total_len >= 0.5 * total_len){
			N50 = contig[k];
			break;
		}
	}
	printf("The number of contig is %d\n",n);
	printf("The maximum contig length is %d\n",contig[n-1]);
	printf("The N50 is %d\n",N50);
	printf("The average contig length is %d\n",total_len/n);
	fclose(inFile);
	fclose(outFile);

	return 0;
}

//function partition recursively calling mergesort to sort ths list
void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
//mergeSort to sort the list (O(nlgN))
void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
			
