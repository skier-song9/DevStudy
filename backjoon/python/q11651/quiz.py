from sys import stdin
n = int(stdin.readline())
nlist = []
for i in range(n):
    nlist.append(list(map(int,stdin.readline().split())))
nlist.sort(key = lambda xy : (xy[1],xy[0]))
for e in nlist:
    print(e[0], e[1])