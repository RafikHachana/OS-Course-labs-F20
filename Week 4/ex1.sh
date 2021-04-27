#!/bin/bash

N=10

gcc ex1.c -o ex1

for(( i = 1 ; i<=$N ; i++ ))
do
	./ex1
done