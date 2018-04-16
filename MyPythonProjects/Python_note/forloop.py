for x in range(10):
    for y in range(1, x + 1):
        print('%d * %d = %d' %(x, y, x * y), end='  ')
    print()