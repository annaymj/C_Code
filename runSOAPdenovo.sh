#!/bin/bash -l

<<comment
This is a master script to call other script to run SOAPdenovo assembly and evaluate the result

comment

if [[ $# -lt 1 ]]; then
	echo "Usage: $0 <kmer>"
	exit
fi

module load soapdenovo2/r240

mkdir soapdenovo-k$1
cp config soapdenovo-k$1/
cd soapdenovo-k$1
echo "kmer = $1"

time SOAPdenovo127mer all -s config -o soapdenovo-k$1 -K $1 -p 24

