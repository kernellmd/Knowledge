#!/bin/bash
############################  
#File Name: printit.sh
#Feature: Use function to repeat information.
#Author: kernellmd 
#Created Time: 2018-07-05 12:46:20
############################  

function printit(){
	echo -n "Your choice is "     # 加上 -n 可以不斷行繼續在同一行顯示
}

echo "This program will print your selection !"
case ${1} in
  "one")
	printit; echo ${1} | tr 'a-z' 'A-Z'  # 將參數做大小寫轉換！
	;;
  "two")
	printit; echo ${1} | tr 'a-z' 'A-Z'
	;;
  "three")
	printit; echo ${1} | tr 'a-z' 'A-Z'
	;;
  *)
	echo "Usage ${0} {one|two|three}"
	;;
esac
