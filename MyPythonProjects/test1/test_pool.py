#!/usr/bin/env python3
#-*- coding: utf-8 -*-  
############################  
#File Name: test_pool.py
#Author: kernellmd 
#Created Time: 2018-06-16 19:58:21
############################  

import os
from time import sleep
from multiprocessing import Pool

def worker(num):
	for i in range(5):
		print("pid = {}, num = {}".format(os.getpid(), num))
		sleep(1)

#进程池中最多有3个进程一起执行
pool = Pool(3)

for i in range(10):
	print("main {}".format(i))
	#向进程池中添加任务，如果数量超过3，则等待进程
	#池中的正在执行的任务完成
	pool.apply_async(worker, (i,))

#关闭进程池，不能再添加任务，即使不执行也不可以
pool.close()
#主进程阻塞，等待进程池中的任务完成，否则主进程会立即结束
#进程池中的任务也会随之结束
pool.join()
