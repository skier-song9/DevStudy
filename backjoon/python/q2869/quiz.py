from sys import stdin
a, b, v = map(int,stdin.readline().split())
# a(day+1) - b day <= v
day = int((v - a)/(a-b))
if v - (a*(day+1) -b*day) == 0:
    print(day+1)
else:
    print(day+2)

'''
1. u d u >> 2
2 u d u


'''