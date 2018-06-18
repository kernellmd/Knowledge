#!/usr/bin/env python3
#-*- coding: utf-8 -*-  
############################  
#File Name: test_fork.py
#Author: kernellmd 
#Created Time: 2018-06-16 02:23:46
############################  

import os
from time import sleep

ret = os.fork()

if ret == 0:
    while True:
        #getpid()获得当前进程id，getppid()获得父进程id
        print("child!", os.getpid(), os.getppid())
        sleep(1)
else:
    while True:
        print("parent!", os.getpid(), os.getppid())
        sleep(1)
