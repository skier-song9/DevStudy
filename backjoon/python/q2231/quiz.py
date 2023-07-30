import math,sys
n = int(input())
for i in range(1,n):
    sol = i
    m = i
    length = int(math.log10(i))
    for j in range(length,0,-1):
        temp = int(i / 10**(j))
        m+=temp
        i -= temp * 10**(j)
    m += i % 10
    if m == n:
        break
else:
    print(0)
    sys.exit(0)
print(sol)