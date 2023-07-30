from sys import stdin
people = []
case = int(stdin.readline())
rank = []
for i in range(case):
    people.append(list(map(int,stdin.readline().split())))
for e in people:
    r = 1
    for i in people:
        x, y = 0, 0
        if e[0] < i[0]:
            x = 1
        if e[1] < i[1]:
            y = 1
        if x*y == 1:
            r += 1
    rank.append(r)
for item in rank:
    print(item)


