from sys import stdin
from collections import deque
input = stdin.readline
case = int(input())
while case:
    input()
    N,M = map(int,input().split())
    nlist = (list(map(int,input().split())))
    mlist = (list(map(int, input().split())))
    nlist = deque(sorted(nlist))
    mlist = deque(sorted(mlist))
    while len(mlist) > 0 and len(nlist) > 0:
        nn = nlist.popleft()
        mm = mlist.popleft()
        if nn < mm:
            mlist.appendleft(mm)
        else:
            nlist.appendleft(nn)
    if len(mlist)==0:
        print('S')
    else:
        print('B')
    case-=1