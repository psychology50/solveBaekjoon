import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

def dfs(cache, left, right, n):
    if left >= n or right >= n:
        return 0
    
    if cache[left][right] != -1:
        return cache[left][right]

    if a[left] > b[right]:
        cache[left][right] = dfs(cache, left, right+1, n) + b[right]
    else:
        throw_both = dfs(cache, left+1, right, n)
        throw_left = dfs(cache, left+1, right+1, n)
        cache[left][right] = max(throw_both, throw_left)
    return cache[left][right]

def solution():
    cache = [[-1]*n for _ in range(n)]
    dfs(cache, 0, 0, n)
    print(cache[0][0])

solution()