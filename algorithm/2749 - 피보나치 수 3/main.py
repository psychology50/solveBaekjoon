import sys

input = sys.stdin.readline

'''
def solution():
    n = int(input())
    mod = 1000000
    cycle = (mod // 10) * 15
    cache = [0, 1]

    for i in range(2, cycle):
        cache.append((cache[i-1] + cache[i-2]) % mod)
        
    print(cache[n%cycle])
'''
def solution():
    n = int(input())
    MOD = 100000
    cache = [0, 1]

    for i in range(2, 1000000):
        cache.append((cache[i-1] + cache[i-2]) % MOD)

solution()