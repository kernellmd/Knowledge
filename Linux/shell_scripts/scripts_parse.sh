#!/bin/bash
############################  
#File Name: scripts_parse.sh
#Feature: how bash parse shell scripts
#Author: kernellmd 
#Created Time: 2018-07-04 10:32:47
############################  

echo "The script name is        ==> ${0}"
echo "Total parameter number is ==> $#"
[ "$#" -lt 2 ] && echo "The number of parameter is less than 2.  Stop here." && exit 0
echo "Your whole parameter is   ==> '$@'"
echo "The 1st parameter         ==> ${1}"
echo "The 2nd parameter         ==> ${2}"
