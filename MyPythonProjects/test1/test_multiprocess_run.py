#!/usr/bin/env python3
#-*- coding: utf-8 -*-  
############################  
#File Name: test_multiprocess_run.py
#Author: kernellmd 
#Created Time: 2018-06-16 18:57:59
############################  

from multiprocessing import Process
from time import sleep

class MyProcess(Process):
    #重写process子类的run方法
#    while True:
    print("in the instance of MyProcess")
    #sleep(1)

p = MyProcess()

#start函数会调用进程对象中的run方法
p.start()
p.join()
print("end!")
