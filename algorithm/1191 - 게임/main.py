import sys
input = sys.stdin.readline
from collections import deque

def find_position(board, n):
    for row in range(n):
        for col in range(n):
            if board[row][col] == 'A':
                row_a = row
                col_a = col
            if board[row][col] == 'B':
                row_b = row
                col_b = col
    return row_a, col_a, row_b, col_b

def dfs(board, n, a, b):
    queue = deque()
    queue.append(a)
    queue.append(b)
    vertor = [(-1, 0), (0, 1), (1, 0), (0, -1)]


    return

def solution():
    t = int(input())
    for _ in range(t):
        n = int(input())
        board = [input().split() for _ in range(n)]
        a, b = find_position(board, n)
        dfs(board, n, a, b)

solution()