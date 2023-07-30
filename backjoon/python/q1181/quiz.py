from sys import stdin
ctn = int(stdin.readline())
wordslist = [[] for _ in range(0,50)]
for i in range(ctn):
    word = stdin.readline().rstrip()
    if word not in wordslist[len(word)-1]:
        wordslist[len(word)-1].append(word)
        wordslist[len(word) - 1].sort()

for e in wordslist:
    if len(e)>0:
        for word in e:
            print(word)

# print(wordslist)