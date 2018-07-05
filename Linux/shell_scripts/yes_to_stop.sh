#!/bin/bash
############################  
#File Name: yes_to_stop.sh
#Feature: Repeat question until user input correct answer.
#Author: kernellmd 
#Created Time: 2018-07-05 15:45:03
############################  

while [ "${yn}" != "yes" -a "${yn}" != "YES" ]
do
	read -p "Please input yes/YES to stop this program: " yn
done
echo "OK! you input the correct answer."
