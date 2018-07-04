#!/bin/bash
############################  
#File Name: squre_brackets_test.sh
#Feature: show user's choice
#Author: kernellmd 
#Created Time: 2018-07-04 10:12:49
############################  

read -p "Please input (Y/N): " yn
[ "${yn}" == "Y" -o "${yn}" == "y" ] && echo "OK, continue" && exit 0
[ "${yn}" == "N" -o "${yn}" == "n" ] && echo "Oh, interrupt!" && exit 0
echo "I don't know what your choice is" && exit 0
