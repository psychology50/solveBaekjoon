import sys
sys.setrecursionlimit(100000)

def factorial(nb):
    if (nb == 0 or nb == 1):
        return 1
    return (nb * factorial(nb - 1))

def solution():
    n, k = map(int, input().split())
    result = factorial(n) // (factorial(n-k) * factorial(k))
    print(result % 10007)

solution()