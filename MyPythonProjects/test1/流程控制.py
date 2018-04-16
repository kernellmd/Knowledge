##永真循环
#while True:
#    print('loop')


#from time import sleep
#n = 10
#while n > 0:
#    print(n)
#    n -= 1
#    sleep(1)

#n = 50

#while True:
#    x = int(input('请输入一个数：'))

#    if x == n:
#        print('恭喜你，猜对了！')
#        break
#    elif x < n:
#        print('猜小了')
#        continue
#    elif x > n:
#        print('猜大了')
#        continue
'''
What is the difference between following words in English technical document system? 
Specification 
Reference 
Tutorial 
Guide 
Manual
'''

#break只退出当前的循环（如果是嵌套循环，则退出内层循环）
for x in range(10):
    if x == 5:
        break
    else:
        print('x = %d' %(x), end = ' ')
        for y in range(10):
            if y == 5:
                break
            else:
                print("y = %d" %(y), end = ' ')
        print()