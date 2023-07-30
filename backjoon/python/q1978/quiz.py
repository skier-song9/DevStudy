t = int(input())
numbers = list(map(int,input().split()))
sol = 0
for i in range(t):
    n = numbers[i]
    if n == 1:
        continue
    for j in range(2,n):
        if n % j == 0:
            break
    else:
        sol+=1
print(sol)

