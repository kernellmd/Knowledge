name = 'kernel'
age = 24
#str是工厂函数，或者叫构造函数
person = name + ' ' + str(age) 
print(person)
a = [1, 2, 3]
b = [4, 5, 6]
c = [7, 8, 9]

print(list(zip(a, b, c)))


l = [1, 2, 3]  
x = [4, 5, 6]  
print(list(zip(l, x)))  
  
#x = [4, 5]  
#print(list(zip(l, x)))  
  
y = (7, 8, 9)  
print(list(zip(l, x, y)))  
  
lxy = list(zip(l, x, y))  
print(list(zip(*lxy)))  

l = [1, 7, 3, 12]
l.reverse()
print(l)