import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

def scan_board(visited):
    for i in range(n):
        for j in range(m):
            if board[i][j] == 2:
                row, col = i, j
            if board[i][j] == 1:
                visited[i][j] = -1
    return row, col

def bfs():
    vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    visited = [[0]*m for _ in range(n)]
    row, col = scan_board(visited)
    queue = deque()
    queue.append([row, col])

    while queue:
        y, x = queue.popleft()
        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < n and 0 <= m_x < m:
                if visited[m_y][m_x] == -1:
                    visited[m_y][m_x] = visited[y][x] + 1
                    queue.append([m_y, m_x])
    return visited

def solution():
    result = bfs()
    for i in range(len(result)):
        for j in range(len(result[i])):
            print("{}".format(str(result[i][j])), end = ' ')
        print()

solution()