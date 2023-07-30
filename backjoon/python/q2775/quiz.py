t = int(input())
while t:
    a = int(input())
    b = int(input())
    total = 0
    f0 = [i for i in range(1,b+1)]
    for f in range(1,a+1):
        temp = f0.copy()
        for h in range(1,b):
            f0[h]=f0[h-1]+temp[h]
    print(f0[b-1])
    t-=1
