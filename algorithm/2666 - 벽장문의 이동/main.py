
''' idx 의 조건 주기가 너무 까다롭다.......
def recursive(idx, cache, open1, open2):
    cache[open1][idx] = cache[open1][open2] + abs(idx - open1)
    cache[idx][open2] = cache[open1][open2] + abs(idx - open2)

def solution():
    n = int(input())
    open1, open2 = map(int, input().split())
    cache = [[0]*(n+1) for _ in range(n+1)]
    check_cnt = int(input())
    check_num = [int(input()) for _ in range(check_cnt)]

    for idx in check_num:
        open1, open2 = recursive(idx, cache, open1, open2)
'''
import sys
input = sys.stdin.readline

n = int(input())
open1, open2 = map(int, input().split())
check_cnt = int(input())
check_num = [int(input()) for _ in range(check_cnt)]
cache = [[[-1]*(n+1) for _ in range(n+1)] for _ in range(check_cnt)]

def dfs(idx, open1, open2):
    if idx == check_cnt: # 깊이 제한
        return 0
    
    if not cache[idx][open1][open2] == -1:
        return cache[idx][open1][open2]
    
    move_open1 = dfs(idx+1, check_num[idx], open2) + abs(check_num[idx] - open1)
    move_open2 = dfs(idx+1, open1, check_num[idx]) + abs(check_num[idx] - open2)
    cache[idx][open1][open2] = min(move_open1, move_open2)
    
    return cache[idx][open1][open2]

def solution():
    print(dfs(0, open1, open2))

solution()