from sys import stdin
input = stdin.readline
case, n = map(int,input().split())
lines = []
for _ in range(case):
    lines.append(int(input()))
for one_line in range(int(sum(lines)/n),0,-1):
    count = 0
    for e in lines:
        count += e//one_line
    if count == n:
        print(one_line)
        break