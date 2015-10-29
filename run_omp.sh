#!/bin/bash
for i in {1..16};
do echo "$i threads";
OMP_NUM_THREADS=$i ./Velvet_omp velvet.fas velvet.out;
done

