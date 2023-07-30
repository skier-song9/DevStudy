from sys import stdin
from itertools import combinations
n,m = map(int,stdin.readline().split())
cards = list(map(int,stdin.readline().split()))
nc3 = list(map(list,combinations(cards,3)))
blackjack = max(filter(lambda x : sum(x) <= m ,nc3))

print(sum(blackjack))