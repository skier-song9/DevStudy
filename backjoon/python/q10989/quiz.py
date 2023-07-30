from sys import stdin
nlist = [0] * 10000
n = int(stdin.readline())
for _ in range(0,n):
    idx = int(stdin.readline()) - 1
    nlist[idx] += 1
for idx in range(10000):
    if nlist[idx] != 0:
        for _ in range(0,idx):
            print(idx+1)
