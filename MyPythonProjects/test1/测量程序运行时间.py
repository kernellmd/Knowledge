#此程序运行28s+
import time
start_time = time.time()
sum = 0
for i in range(10000000):
    sum += 1

end_time = time.time()
print(end_time - start_time)
