'''
局部变量
会覆盖闭包变量
会覆盖全局变量
会覆盖内建变量
'''

from math import pi

#pi = 3
def foo_outer():
    #pi = 3.1

    def foo_inner():
        #pi = 3.14
        print(pi)

    foo_inner()

foo_outer()