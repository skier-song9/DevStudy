from sys import stdin
input = stdin.readline
A,B = input().split()
Asum = sum(map(int,list(A)))
result = 0
for b in range(len(B)):
    result += int(B[b]) * Asum
print(result)

'''
abc de
ad + ae + bd + be + cd + ce
= d(a+b+c) + e(a+b+c)

'''