# 5x+3y = N
from sys import stdin
from itertools import permutations
n = int(stdin.readline())
# xy = list(map(list,(permutations(range(0,int(n/3)+1),2))))
# nlist=list(filter(lambda x: x[1] == n,
#        map(lambda e: [e,5*(e[0])+3*(e[1])],xy)
#        ))
# if len(nlist) == 0:
#     print(-1)
# else:
#     print(min(map(lambda e: sum(e[0]),nlist)))

isEnd = False
for a in range(0,int(n/3)+1):
    for b in range(0,int(n/5)+1):
        if (3*a + 5*b) == n:
            print(a+b)
            isEnd = True
            break
    if isEnd :
        break
else:
    print(-1)