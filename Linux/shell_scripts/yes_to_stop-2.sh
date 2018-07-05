#!/bin/bash
############################  
#File Name: yes_to_stop-2.sh
#Feature: Repeat question until user input correct answer.
#Author: kernellmd 
#Created Time: 2018-07-05 15:47:45
############################  

until [ "${yn}" == "yes" -o "${yn}" == "YES" ]
do
	read -p "Please input yes/YES to stop this program: " yn
done
echo "OK! you input the correct answer."
