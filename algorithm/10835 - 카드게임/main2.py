import sys
sys.setrecursionlimit = 10**7
input = sys.stdin.readline

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    cache = [[0]*(n+1) for _ in range(n+1)]
    
    for left in range(1, n+1):
        for right in range(1, n+1):
            if a[left-1] > b[right-1]:
                cache[left][right] = max(cache[left][right-1] + b[right-1], cache[left-1][right], cache[left-1][right-1])
            else:
                cache[left][right] = max(cache[left-1][right], cache[left-1][right-1])
    print(cache[n][n])

solution()