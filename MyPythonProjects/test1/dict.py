#字典推导式
values = ['tom', 'jerry', 'dog']
dict = {key: values[key] for key in range(3)}
print(dict)
