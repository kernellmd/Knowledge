#!/bin/bash
############################  
#File Name: squre_brackets_test.sh
#Feature: show user's choice
#Author: kernellmd 
#Created Time: 2018-07-04 10:12:49
############################  

read -p "Please input (Y/N): " yn

if [ "${yn}" == "Y" ]||[ "${yn}" == "y" ];then
	echo "OK, continue"
	exit 0
fi

if [ "${yn}" == "N" ] || [ "${yn}" == "n" ];then
	echo "Oh, interrupt!"
	exit 0
fi

echo "I don't know what your choice is" && exit 0
