#!/bin/bash
corecount=16

#Affinity Scheduling
for affinity in none scatter compact;

do
	#Thread Count
	for ((t=1; t<=corecount; t++));
#	do printf "${t} ${affinity}";
	do echo "${t} ${affinity}";
	   KMP_AFFINITY=${affinity} OMP_NUM_THREADS=${t} ./Velvet_omp velvet.fas velvet_${affinity}.out;
	wait;
#	done 
	done >${affinity}.Velvet_ompOut
done

