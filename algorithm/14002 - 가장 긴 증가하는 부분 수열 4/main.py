import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    cache = [0]*n
    result = []

    for i in range(n):
        for j in range(i):
            if a[i] > a[j] and cache[i] < cache[j]:
                cache[i] = cache[j]
        cache[i] += 1
    print(max(cache))

    order = max(cache)
    for i in range(n-1, -1, -1):
        if cache[i] == order:
            result.append(a[i])
            order -= 1
    result.reverse()

    for i in result:
        print(i, end=' ')

solution()