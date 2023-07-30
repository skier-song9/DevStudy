from sys import stdin
n = stdin.readline()
line = list(input())
h = 0
for idx,e in enumerate(line):
    chr = ord(e)-ord('a')+1
    h += (chr) * (31**(idx))
print(h%1234567891)
