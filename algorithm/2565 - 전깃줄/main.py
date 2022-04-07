import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    pole = [False]*501
    for _ in range(n):
        a, b = map(int, input().split())
        pole[a] = b
    cache = [1]*501

    for i in range(1, 501):
        if not pole[i]:
            continue
        for j in range(1, i):
            if not pole[j]:
                continue
            if pole[i] > pole[j] and cache[i] < cache[j] + 1:
                cache[i] = cache[j] + 1
    print(n - max(cache))

solution()