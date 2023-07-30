from sys import stdin
def issame(block,start):
    global ctn
    ctn+=1
    if ctn % 2 == 0:
        if block != start:
            return 0
        else:
            return 1
    else:
        if block == start:
            return 0
        else:
            return 1
def toggle_start(start):
    if start == 'W':
        return 'B'
    else:
        return 'W'
h,w = map(int,stdin.readline().split())
boards = []
for i in range(h):
    boards.append(stdin.readline().rstrip())
changes = 50*50
for xs in range(w-7):
    for ys in range(h-7):
        board = list(map(lambda x: x[xs:xs+8],boards[ys:ys+8]))
        start = board[0][0]
        change_a = 0
        for e in board.copy():
            ctn = 0
            change_a+=sum(map(lambda x:issame(x,start),list(e)))
            start = toggle_start(start)
        start = toggle_start(start)
        change_b = 0
        for ee in board.copy():
            ctn = 0
            change_b += sum(map(lambda x: issame(x, start), list(ee)))
            start = toggle_start(start)
        change = min([change_a,change_b])
        if change < changes:
            changes = change
print(changes)
