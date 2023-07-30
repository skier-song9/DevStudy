import sys

def solution(h,w,n):
    xx = int(n/h) if n%h==0 else int(n/h)+1
    yy = h if (n%h) == 0 else n%h
    print(str(yy)+(('0'+str(xx)) if xx < 10 else str(xx)))

# sys.stdin = open('./input.txt')
# t = int(sys.stdin.readline())
t = int(input())
while t:
    h,w,n = map(int,input().split())
    solution(h,w,n)
    t-=1
