''' 최악의 경우 N 1024 * 1024 , M 1 1 1024 1024 ... 왜 시간초과?  
def solution():
    n, m = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(n)]

    for _ in range(m):
        x1, y1, x2, y2 = map(int, input().split())
        result = 0
        for row in range(x1 - 1, x2):
            for col in range(y1 - 1, y2):
                result += board[row][col]
        print(result)
'''

# time error ... dfs의 시간 복잡도는 O(N). 알고리즘의 문제가 아니라면?
# 반복 횟수가 m이라서 문제. 값을 저장해야 하는 dp 문제였다.

'''
from collections import deque

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
move = [(0, 1), (1, 0), (1, 1)]

def bfs(x1, y1, x2, y2):
    visited = [[0]*n for _ in range(n)]
    queue = deque()
    total = []

    total.append(board[y1][x1])
    visited[y1][x1] = 1
    queue.append([y1, x1])

    while queue:
        row, col = queue.popleft()
        for q, p in move:
            m_y = row + q
            m_x = col + p
            if m_y <= y2 and m_x <= x2:
                if not visited[m_y][m_x]:
                    total.append(board[m_y][m_x])
                    visited[m_y][m_x] = 1
                    queue.append([m_y, m_x])
    print(sum(total))

def solution():
    for _ in range(m):
        y1, x1, y2, x2 = map(int, input().split())
        bfs(x1 -1, y1 - 1, x2 - 1, y2 - 1)
'''

# dp를 먼저 만들어 놓고 시작해야 m번 반복을 하지 않는다.
# dp의 값을 저장하는 기준은 무엇으로?

import sys
input = sys.stdin.readline
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
cache = [[0]*n for _ in range(n)]

''' recursive limit
def fill_cache(row, col):
    if row == n - 1 and col == n - 1:
        return cache[row][col]

    if row == n - 1:
        cache[row][col] = fill_cache(row, col + 1) + board[row][col]
    elif col == n - 1:
        cache[row][col] = fill_cache(row + 1, col) + board[row][col]

    if cache[row][col] == 0:
        cache[row][col] = fill_cache(row + 1, col) + fill_cache(row, col + 1) + board[row][col] - cache[row+ 1][col + 1]
    return cache[row][col]
'''
def solution():
    cache[n - 1][n - 1] = board[n - 1][n - 1]

    for row in range(n-1, -1, -1):
        for col in range(n-1, -1, -1):
            if row == n - 1 and col == n - 1:
                continue
            elif row == n - 1:
                cache[row][col] = cache[row][col+1] + board[row][col]
                continue
            elif col == n - 1:
                cache[row][col] = cache[row+1][col] + board[row][col]
                continue
            cache[row][col] = cache[row+1][col] + cache[row][col+1] - cache[row+1][col+1] + board[row][col] 

    for _ in range(m):
        y1, x1, y2, x2 = map(int, input().split())
        if y2 == n and x2 == n:
            print(cache[y1 - 1][x1 - 1])
        elif y2 == n:
            print(cache[y1 - 1][x1 - 1] - cache[y1 - 1][x2])
        elif x2 == n:
            print(cache[y1 - 1][x1 - 1] - cache[y2][x1 - 1])
        else:
            print(cache[y1 - 1][x1 - 1] - cache[y2][x1 - 1] - cache[y1 - 1][x2] + cache[y2][x2])

solution()