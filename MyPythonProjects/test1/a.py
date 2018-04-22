va = ['dobi', 'a', 'dog']

print('a1', id(va))

class A():
    def __init__(self):
        pass

    def rtn(self):
        global va
        va.insert(1,'is')
        print('a3', id(va))
        return va

print('a2', va)
