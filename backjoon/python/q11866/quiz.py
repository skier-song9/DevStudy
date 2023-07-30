from sys import stdin
from collections import deque
n,k = map(int,stdin.readline().split())
ndq = deque([i for i in range(1,n+1)])
permutation = []
while ndq:
    # if len(ndq) / k < 1 :
    #     while ndq:
    #         permutation.append(ndq.popleft())
    #     break
    for i in range(k-1):
        ndq.append(ndq.popleft())
    permutation.append(ndq.popleft())

print('<',end='')
for idx,e in enumerate(permutation):
    if idx == len(permutation)-1:
        print(e,end='')
        break
    print(e,end=', ')
print('>')