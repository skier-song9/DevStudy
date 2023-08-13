from sys import stdin
case = int(stdin.readline())
for _ in range(case):
    a,b = map(int,stdin.readline().split())
    a = a%10
    last = 0
    if a in [1,0,5,6]:
        last = a%10 if a!=0 else 10
    elif a in [2,3,7,8]:
        b = (b%4) if b%4 != 0 else 4
        last = (a**(b)) % 10
    else: #[4,9]
        b = (b % 2) if b % 2 != 0 else 2
        last = (a ** (b)) % 10
    print(last)
