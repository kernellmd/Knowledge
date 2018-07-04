#!/bin/bash
############################  
#File Name: shift_paras.sh
#Feature: show the effect of shift function.
#Author: kernellmd 
#Created Time: 2018-07-04 10:46:00
############################  

echo "Total parameter number is ==> $#"
echo "Your whole parameter is   ==> '$@'"
shift   # 進行第一次『一個變數的 shift 』
echo "Total parameter number is ==> $#"
echo "Your whole parameter is   ==> '$@'"
shift 3 # 進行第二次『三個變數的 shift 』
echo "Total parameter number is ==> $#"
echo "Your whole parameter is   ==> '$@'"
