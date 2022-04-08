import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    a = set(input().split())
    m = int(input())
    b = list(input().split())

    for p in b:
        if p in a:
            print(1)
        else:
            print(0)

solution()