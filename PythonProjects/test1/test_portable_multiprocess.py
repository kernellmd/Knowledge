#!/usr/bin/env python3
#-*- coding: utf-8 -*-  
############################  
#File Name: test_portable_multiprocess.py
#Author: kernellmd 
#Created Time: 2018-06-16 18:17:38
############################  

#使用fork()函数不具有可移植性
#Python提供了multiprocessing模块来实现多进程的可移植性

from time import sleep
from multiprocessing import Process

def test():
#    while True:
    print("in test!")
    sleep(1)

#test函数执行结束，子进程即结束
p = Process(target=test)
#开始执行子进程
p.start()

#while true:
#    print("parent!")
#    sleep(1)

#父进程阻塞，等待子进程结束
p.join()
print("parent end!")
