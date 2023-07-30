from sys import stdin
case = int(stdin.readline())
nlist=[]
while case:
    nlist.append(int(stdin.readline()))
    case-=1
nlist.sort()
length = len(nlist)
print(round(sum(nlist)/length))
print(nlist[int(length/2)])
ndict = {}
for e in nlist:
    if ndict.get(f'{e}') != None:
        ndict[f'{e}'] += 1
    else:
        ndict[f'{e}'] = 1
mode = list(map(int,list(filter(lambda x : ndict.get(f'{x}') == max(ndict.values()), ndict.keys()))))
if len(mode) > 1:
    mode.sort()
    print(mode[1])
else:
    print(mode[0])
print(max(nlist)-min(nlist))