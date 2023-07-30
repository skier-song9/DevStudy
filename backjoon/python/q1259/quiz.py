from sys import stdin
while 1:
    isPalindrome = True
    nlist = list(map(int,list((stdin.readline()).rstrip())))
    if nlist[0] == 0:
        break
    while len(nlist) > 1:
        if nlist.pop(0) - nlist.pop((len(nlist)-1)) == 0:
            continue

        else:
            isPalindrome = False
    print('yes' if isPalindrome else 'no')

