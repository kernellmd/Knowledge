#!/bin/bash
############################  
#File Name: cal_sum_1_to_100.sh
#Feature: Try do calculate 1+2+....+${your_input}
#Author: kernellmd 
#Created Time: 2018-07-05 16:59:25
############################  

read -p "Please input a number, I will count for 1+2+...+your_input: " nu

s=0
for (( i=1; i<=${nu}; i++ ))  #i++也可以携程i=i+1
do
	s=$((${s}+${i}))
done
echo "The result of '1+2+3+...+${nu}' is ==> ${s}"
