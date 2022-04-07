import sys
from collections import deque

input = sys.stdin.readline

def bfs(n, m, board):
    vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    visited = [[[0]*2 for _ in range(m)] for _ in range(n)]
    queue = deque()
    
    queue.append([0, 0, 0])
    visited[0][0][0] = 1

    while queue:
        y, x, flag = queue.popleft()
        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < n and 0 <= m_x < m:
                if board[m_y][m_x] == 0 and visited[m_y][m_x][flag] == 0:
                    visited[m_y][m_x][flag] = visited[y][x][flag] + 1
                    queue.append([m_y, m_x, flag])
                if board[m_y][m_x] == 1 and flag == 0:
                    visited[m_y][m_x][flag + 1] = visited[y][x][flag] + 1
                    queue.append([m_y, m_x, 1])
    if visited[n-1][m-1][0] == 0 and visited[n-1][m-1][1] == 0:
        return -1
    elif visited[n-1][m-1][0] == 0:
        return visited[n-1][m-1][1]
    elif visited[n-1][m-1][1] == 0:
        return visited[n-1][m-1][0]
    else:
        return min(visited[n-1][m-1][0], visited[n-1][m-1][1])

def solution():
    n, m = map(int, input().split())
    board = [list(map(int, input().rstrip())) for _ in range(n)]

    print(bfs(n, m, board))

solution()