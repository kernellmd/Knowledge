#!/bin/bash
############################  
#File Name: show123-2.sh
#Feature: Use function to repeat information.
#Author: kernellmd 
#Created Time: 2018-07-05 12:52:05
############################  

function printit(){
	echo "Your choice is ${1}"   # 這個 $1 必須要參考底下指令的下達
}

echo "This program will print your selection !"
case ${1} in
  "one")
	printit 1  # 請注意， printit 指令後面還有接參數！
	;;
  "two")
	printit 2
	;;
  "three")
	printit 3
	;;
  *)
	echo "Usage ${0} {one|two|three}"
	;;
esac
