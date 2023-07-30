from sys import stdin
import sys
n = int(stdin.readline())
nstack = [] # 1 2 3 4
poppush=[] # + + + +
cur_numb = 1 # 5
while n:
    numb = int(stdin.readline())
    while cur_numb <= numb:
        nstack.append(cur_numb)
        poppush.append('+')
        cur_numb+=1
    while cur_numb > numb:
        if len(nstack)==0:
            break
        popped = nstack.pop()
        poppush.append('-')
        if popped == numb:
            break
    if popped != numb:
        print("NO")
        sys.exit(0)
    n-=1
for e in poppush:
    print(e)