from collections import deque
from sys import stdin
t = int(stdin.readline())
while t:
    n,m = map(int,stdin.readline().split())
    ndq = deque(list(map(int,stdin.readline().split())))
    count = 0
    while ndq:
        max_n = max(ndq)
        temp = ndq.popleft()
        m-=1
        if max_n == temp:
            count += 1
            if m < 0 :
                print(count)
                break;
        else:
            ndq.append(temp)
            if m < 0:
                m = len(ndq)-1

    t-=1