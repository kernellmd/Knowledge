#!/bin/bash
############################  
#File Name: showname.sh
#Feature: show the full name
#Author: kernellmd 
#Created Time: 2018-06-26 19:04:14
############################  

read -p "Please input your first name:" firstname
read -p "Please input your last name:" lastname
echo -e "\nYour full name is:"${firstname} ${lastname}
