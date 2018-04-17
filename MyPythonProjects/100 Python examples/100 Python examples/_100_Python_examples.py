"""
题目描述：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后，再去掉不满足条件的排列。
"""
num = 0
for hundreds in range(1, 5):
    var = hundreds * 100
    #print('var1 = ' + str(var))
    for tens in range(1, 5):
        if tens != hundreds:
            var += tens * 10 
            #print('var2 = ' + str(var))
            for ones in range(1, 5):
                if ones != hundreds and ones != tens:
                    var += ones
                    print(var)
                    var -= ones
                    num += 1
                else:
                    continue
            var -= tens * 10
        else:
            continue
print(num)