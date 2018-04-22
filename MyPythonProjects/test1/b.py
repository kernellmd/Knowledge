from a import A
#from a import * 改成这样print(id(va))可以正常输出
#会将a.py执行一遍，但是只导入了A，b.py的命名控件中没有va
#import a
print('b', A)
#print(id(va))
class A():
    a = 1
    b = [a + i for i in range(3)]