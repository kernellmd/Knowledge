#!/bin/bash
############################  
#File Name: multiplying.sh
#Feature: User inputs 2 integer numbers; program will cross these two numbers.
#Author: kernellmd 
#Created Time: 2018-07-01 17:10:55
############################  

#bash shell预设仅支持到整数
#运算方式：var=$((運算內容))
echo -e "You SHOULD input 2 numbers, I will multiplying them! \n"
read -p "first number:  " firstnu
read -p "second number: " secnu
total=$((${firstnu}*${secnu}))  
#还可以使用declare -i total=${firstnu}*${secnu}，即声明total为整数
echo -e "\nThe result of ${firstnu} x ${secnu} is ${total}."
