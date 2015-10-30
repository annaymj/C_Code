/*This is the script to merge forward read file and backward read file
each file consistts a four line unit, including the DNA sequence quality info, 
the last line is the DNA sequence*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(int argc, char *argv[])
{
	int i;
  	char ch;
  	char line[200];
	FILE *fs1 = fopen( argv[1], "r" );
  	FILE *fs2 = fopen( argv[2], "r" );
  	FILE *ft ;

        if ( argc != 4 )
                printf( "usage: %s filename", argv[0] );
   	
	ft = fopen(argv[3],"w");
          	if (fs1 ==NULL || fs2 == NULL || ft ==NULL){
         		printf("cannot find file \n");
         		exit(0);
        	}
	while(fgets(line, sizeof(line), fs1)!= NULL){
		fprintf(ft,line);
		for (i=0; i <=2; i++){       
			fgets(line, sizeof(line), fs1);
        		fprintf(ft,line);
		}

		for (i=0; i <=3; i++){
			fgets(line, sizeof(line), fs2);
			fprintf(ft,line);
		}

	}
	fclose(ft);
	fclose(fs1);
	fclose(fs2);
	return(0) ;
}
