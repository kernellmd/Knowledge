a = [1, 2, 3]
b = [4, 5, 6]
c = [7, 8, 9]
zip1 = zip(a, b, c)
zip2 = zip(a, b, c)
print(list(zip1))
zip3 = list(zip2)
print(list(zip(*zip3)))
