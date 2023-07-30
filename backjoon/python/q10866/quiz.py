from sys import stdin
from collections import deque
dq = deque([])
def callfunc(wlist):
    if len(wlist)==2:
        x = wlist[1]
    if wlist[0]== "push_front":
        dq.appendleft(x)
    elif wlist[0]== "push_back":
        dq.append(x)
    elif wlist[0]== "pop_front":
        if len(dq)==0:
            print(-1)
            return
        print(dq.popleft())
    elif wlist[0]== "pop_back":
        if len(dq)==0:
            print(-1)
            return
        print(dq.pop())
    elif wlist[0]== "size":
        print(len(dq))
    elif wlist[0]== "empty":
        print(1) if len(dq)==0 else print(0)
    elif wlist[0]== "front":
        if len(dq)==0:
            print(-1)
            return
        dq_front = dq.popleft()
        print(dq_front)
        dq.appendleft(dq_front)
    else:
        if len(dq)==0:
            print(-1)
            return
        dq_back = dq.pop()
        print(dq_back)
        dq.append(dq_back)

case = int(stdin.readline())
while case:
    ins = stdin.readline().split()
    callfunc(ins)
    case-=1