#!/bin/bash
############################  
#File Name: create_3_files.sh
#Feature: Program creates three files, which named by user's input and date command.
#Author: kernellmd 
#Created Time: 2018-06-27 11:26:19
############################  

echo -e "I will use 'touch' command to create 3 files."
read -p "Please input your filename: " filename_tmp

#如果filename_tmp为空串或者未设定，则filename变量的内容设定为“filename”
filename=${filename_tmp:-"default"}_

# 3. 開始利用 date 指令來取得所需要的檔名了；
date1=$(date --date='2 days ago' +%Y%m%d)  # 前兩天的日期
date2=$(date --date='1 days ago' +%Y%m%d)  # 前一天的日期
date3=$(date +%Y%m%d)  # 今天的日期
file1=${filename}${date1}  # 底下三行在設定檔名
file2=${filename}${date2}
file3=${filename}${date3}

# 4. 將檔名建立吧！
touch "${file1}"  # 底下三行在建立檔案
touch "${file2}"
touch "${file3}"
