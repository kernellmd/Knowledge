#!/bin/bash
############################  
#File Name: paras_hello.sh
#Feature: Check $1 is equal to "hello"
#Author: kernellmd 
#Created Time: 2018-07-04 11:20:54
############################  

if [ "${1}" == "hello" ]; then
	echo "Hello, how are you ?"
elif [ "${1}" == "" ]; then
	echo "You MUST input parameters, ex> {${0} someword}"
else
	echo "The only parameter is 'hello', ex> {${0} hello}"
fi
