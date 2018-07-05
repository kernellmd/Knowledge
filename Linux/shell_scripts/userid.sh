#!/bin/bash
############################  
#File Name: userid.sh
#Feature: Use id, finger command to check system account's information.
#Author: kernellmd 
#Created Time: 2018-07-05 16:11:53
############################  

users=$(cut -d ':' -f1 /etc/passwd)    # 擷取帳號名稱
for username in ${users}               # 開始迴圈進行！
do
        id ${username}
done
