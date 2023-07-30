from sys import stdin
case = int(stdin.readline())
while case:
    line = list(stdin.readline().rstrip())
    lps = 0
    for i in line:
        if i == '(':
            lps += 1
        else:
            lps -= 1
        if lps<0:
            print("NO")
            break;
    else:
        if lps == 0:
            print("YES")
        else:
            print("NO")

    case -= 1
