from sys import stdin
from collections import deque
input = stdin.readline
cols = int(input())
password = input().rstrip()
plength = len(password)
try:
    rows = (plength // cols) + ((plength%cols) / (plength%cols))
except:
    rows = (plength // cols)
ptable = deque([])

for r in range(rows-1,0,-1):


def substract(start,end,direction,password,ptable):
    ptable.appendleft(list(password[start:end-1]))

    return ptable

'''         읽는 방향   쓴 방향
a	e	i   ->>         <<<
b	f	j   <<<         >>>
c	g	k   >>>         <<<
d	h	l   <<<         >>>
m   n
>> col = 3 , len(password) = 14
14 % 3 = 2
14 // 3 = 4

'''

