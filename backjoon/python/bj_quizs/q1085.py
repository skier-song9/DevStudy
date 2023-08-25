from sys import stdin
input = stdin.readline
x,y,w,h = map(int,input().split())
result = []
if x < w/2:
    result.append(x)
else:
    result.append(w-x)
if y < h/2:
    result.append(y)
else:
    result.append(h-y)
print(min(result))

