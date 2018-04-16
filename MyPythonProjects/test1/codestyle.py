flag = True
'''
    print ('it\' fale')
'''
#多行注释可以用三个单引号，也可用三个双引号
"""
fasjfd;l
fa;sdfjk;a
fjld;afjkd;
"""

if flag:
    print ('It\'s true')
else:
    print ('it\' fale')


#文档注释
class Person(object):
    '这是一个Person类。。。'
    pass

print(Person.__doc__)
print(abs.__doc__)