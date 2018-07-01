#!/bin/bash
############################  
#File Name: bc_test.sh
#Feature:
#Author: kernellmd 
#Created Time: 2018-07-01 21:08:01
############################  

#!/bin/bash
echo "the result of 1.212*3 is:"
echo "1.212*3" | bc
echo "the result of 3/8 is:"
echo "scale=2;3/8" | bc
var1=192
echo "the var1:"
echo "obase=2;$var1" | bc
var2=11000000
echo "the var2:"
echo "obase=10;ibase=2;$var2" | bc
echo "the result of 10^10 is:"
echo "10^10" | bc
echo "the result of sqrt(100) is:"
echo "sqrt(100)" | bc
