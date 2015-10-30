#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>


int main(int argc, char *argv[]){
	FILE *inFile;
	FILE *outFile;
	char *inMode = "r";
	char *outMode = "w";
	char line[1000];
	char *header[20000];
	char *dna[20000];
	int delete[20000];
	int i=0,j=0,n=1,k,l;
	double tstart, tend, duration;
	
	//check whether input arguemnt is valid
	if (argc != 3){
		printf("usage: %s input_file output_file\n",argv[0]);
	}

	inFile = fopen(argv[1],inMode);
	outFile = fopen(argv[2],outMode);
	tstart = omp_get_wtime();	

	if(inFile == NULL ){
		fprintf(stderr, "Can't open input fasta file");
		exit(1);
	}

	//reading files and store dna sequences in dna[], headfiles in header[]
	else{
		while (fgets(line,sizeof(line),inFile) != NULL){
				if (line[0] == '>'){
					header[i] = malloc(1000 * sizeof(char));
					strcpy(header[i],line);
					i++;
				}
				else{
					dna[j] = malloc(1000 * sizeof(char));
				 	strcpy(dna[j],line);
					j++;
				}
		}
	}

//store subset or duplicated DNA sequences in delete[]

//	#pragma omp parallel  for 
	for (k = 0; k< j; k++){
	#pragma omp parallel  for schedule(dynamic,100)
		for (l = k+1; l < j; l++)
			//if two sequences are exactly the same
			{
			if (strcmp(dna[k], dna[l]) ==0 && k != l){
				delete[k]=-1;
				delete[l]=-1;
			}
			//if string K is subset of string L
			else {
				char K[900];
				char L[900];
				strcpy(K,dna[k]);
				strcpy(L,dna[l]);
				if ( (strstr(strtok(L,"\n"),strtok(K,"\n")) != NULL) && (k != l) && (delete[k] != -1) ){
					delete[k] = -1;
				}
			}
			
		}
	}

//#pragma omp barrier
	//print out the output file and the deleting message
	int count = 0;

	#pragma omp parallel for reduction (+:count) schedule(dynamic,100)
	for (k = 0; k<j; k++){
	//	fprintf(outFile,header[k]);
		//if not in delete
		if( delete[k] != -1 ){
			count++;
			fprintf(outFile,header[k]);
			fprintf(outFile,dna[k]);
		}
		//if in delete
/*		else{
			char header_id[500];
			char *pch;
			strcpy(header_id,header[k]);
			pch = strtok(header_id," ");
			printf("\nDeleting the sequence with id : %s",pch);
			printf("\n%s",dna[k]);
		}
*/	}
	tend = omp_get_wtime();
	duration = tend-tstart;
	printf("\nThe time taken is  %3.10f\n",duration);
	printf("\nThe number of unique sequence is %d\n",count);
	fclose(inFile);
	fclose(outFile);
	return 0;
}
