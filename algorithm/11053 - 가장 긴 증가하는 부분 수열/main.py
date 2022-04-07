import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    cache = [0]*n

    for i in range(n):
        for j in range(i):
            if a[i] > a[j] and cache[i] < cache[j]:
                cache[i] = cache[j]
        cache[i] += 1
    print(max(cache))

solution()