import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
n, m = list(map(int, input().split()))
board = []
target = []
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
for i in range(n):
    col = list(input().rstrip())
    for c in range(len(col)):
        if col[c] == "I":
            target = [i, c]
    board.append(col)

visited = [[0] * m for _ in range(n)]
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

cnt = 0

def dfs(x, y):
    global cnt
    if 0 <= x < n and 0 <= y < m and not visited[x][y]:
        visited[x][y] = 1
        if board[x][y] == 'P':
            cnt += 1
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                if board[nx][ny] != 'X':
                    dfs(nx, ny)


dfs(target[0], target[1])

if not cnt:
    print("TT")
else:
    print(cnt)