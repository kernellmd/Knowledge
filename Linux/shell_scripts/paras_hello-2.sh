#!/bin/bash
############################  
#File Name: paras_hello.sh
#Feature: Show "Hello" from $1.... by using case .... esac
#Author: kernellmd 
#Created Time: 2018-07-04 11:20:54
############################  

case ${1} in
 "hello")
	echo "Hello,how are you?"
	;;
 "")
	echo "You MUST input parameters, ex> {${0} someword}"
	;;
 *)
	echo "Usage ${0} {hello}"
	;;
esac
