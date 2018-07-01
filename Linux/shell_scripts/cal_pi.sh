#!/bin/bash
############################  
#File Name: cal_pi.sh
#Feature: User input a scale number to calculate pi number.
#Author: kernellmd 
#Created Time: 2018-07-01 18:29:03
############################  

echo -e "This program will calculate pi value. \n"
echo -e "You should input a float number to calculate pi value.\n"
read -p "The scale number (10~10000) ? " checking
num=${checking:-"10"}           # 開始判斷有否有輸入數值
echo -e "Starting calculate pi value.  Be patient."
time echo "scale=${num}; 4*a(1)" | bc -lq
exit 0
