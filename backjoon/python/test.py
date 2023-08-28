# from sys import stdin
# input = stdin.readline
while 1:
    line = input()
    if line == '# 0 0':
        break
    name,age,weight = line.split()
    if (int(age) > 17) | (int(weight)>=80):
        print(name,'Senior')
    else:
        print(name,'Junior')
