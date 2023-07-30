from sys import stdin
nlist = list(map(int,stdin.readline().split()))
nlist.sort()
a,b = nlist
divisors=[]
for i in range(1,a+1):
    if a % i == 0 :
        divisors.append(i)
for j in range(len(divisors)-1,-1,-1):
    if b % divisors[j] == 0:
        print(divisors[j])
        print(int(b/divisors[j]) * a)
        break
