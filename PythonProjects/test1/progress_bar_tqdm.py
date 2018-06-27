#!/usr/bin/env python3
#-*- coding: utf-8 -*-  
############################  
#File Name: process_bar_tqdm.py
#Author: kernellmd 
#Created Time: 2018-06-26 15:56:43
############################  

from time import sleep
from tqdm import tqdm
# 这里同样的，tqdm就是这个进度条最常用的一个方法
# 里面存一个可迭代对象
#for i in tqdm(range(1, 500)):
#   # 模拟你的任务
#   #print(i)
#   sleep(0.01)

with tqdm(total=100) as pbar:
	for i in range(20):
#   # 模拟你的任务
		sleep(1)
		#注意20*5=100，循环进行20次更新，每次更新增加5，正好是100
		pbar.update(5)
