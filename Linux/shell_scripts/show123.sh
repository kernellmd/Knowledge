#!/bin/bash
############################  
#File Name: show123.sh
#Feature: This script only accepts the flowing parameter: one, two or three.
#Author: kernellmd 
#Created Time: 2018-07-04 16:51:52
############################  

echo "This program will print your selection !"
# read -p "Input your choice: " choice   # 暫時取消，可以替換！
# case ${choice} in                      # 暫時取消，可以替換！
case ${1} in                             # 現在使用，可以用上面兩行替換！
  "one")
	echo "Your choice is ONE"
	;;
  "two")
	echo "Your choice is TWO"
	;;
  "three")
	echo "Your choice is THREE"
	;;
  *)
	echo "Usage ${0} {one|two|three}"
	;;
esac
