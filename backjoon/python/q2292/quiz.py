# 1  1
# 6  2-7
# 12  8-19
# 18  20-37
# 24  38-61
# 30  62-...
import sys
n = int(input())
k=1
i=0
if n == 1 :
    print(1)
    sys.exit(0)
while 1:
    temp = k + (6*i)
    if k < n <= temp:
        break
    i+=1
    k = temp
print(i+1)