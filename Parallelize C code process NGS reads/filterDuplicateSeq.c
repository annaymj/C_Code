#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if (argc != 3){
		printf("usage: %s input_file output_file",argv[0]);
	}

	inFile = fopen(argv[1],inMode);
	outFile = fopen(argv[2],outMode);

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
	for (k = 0; k< j; k++){
		for (l = 0; l < j; l++){
			if (strcmp(dna[k], dna[l]) ==0 && k != l){
				delete[k]=-1;
				delete[l]=-1;
			}
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
	//print out the output file and the deleting message
	int count = 0;
	for (k = 0; k<j; k++){
		fprintf(outFile,header[k]);
		//if not in delete
		if( delete[k] != -1 ){
			count++;
			fprintf(outFile,dna[k]);
		}
		//if in delete
		else{
			char header_id[500];
			char *pch;
			strcpy(header_id,header[k]);
			pch = strtok(header_id," ");
			printf("\nDeleting the sequence with id : %s",pch);
			printf("\n%s",dna[k]);
		}
	}

	printf("\nThe number of unique sequence is %d\n",count);
	fclose(inFile);
	fclose(outFile);
	return 0;
}
