word = list(input())
a = ord('a')
for i in range(a,a+26):
    # print(chr(i))
    isNotIn = True
    for idx, e in enumerate(word):
        e = ord(e)
        if i-e == 0 :
            print(idx,end=" ")
            isNotIn = False
            break
    if(isNotIn):
        print(-1,end=" ")


# 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
# 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1