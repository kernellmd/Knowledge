##函数定义
#def print_hello(name):
#    print('hello,' + name)

##函数调用
#print_hello('kernellmd')

#有默认参数的函数，默认参数必须在非默认参数的后边
def foo(sex, age, name='kernel'):
#当’=’用于指示关键字参数或默认参数值时, 不要在其两侧使用空格
    print('name = ' + name)
    print('sex = ' + sex)
    print('age = %d' %(age))

#foo('kernellmd', 'male', 24)
foo('male', 24)
