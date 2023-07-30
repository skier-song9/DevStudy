from sys import stdin
n,m,blocks = map(int,stdin.readline().split())
maps = []
solutions = []
for i in range(n):
    maps.append(list(map(int,stdin.readline().split())))
max_height = max(map(max,maps))
for h in range(max_height+1):
    block_used = 0
    block_plus = 0
    for y in range(n):
        for x in range(m):
            if maps[y][x] > h:
                block_plus += (maps[y][x] - h)
            else:
                block_used += (h - maps[y][x])
    if blocks + block_plus < block_used:
        continue
    else:
        solutions.append([(block_used + block_plus * 2) , h])
solutions.sort(key=lambda x:(x[0],-x[1]))
print(solutions[0][0],solutions[0][1])


