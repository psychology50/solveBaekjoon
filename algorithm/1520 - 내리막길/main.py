import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
cache = [[-1]*m for _ in range(n)]
vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def dfs(row, col):
    if row == n - 1 and col == m - 1:
        return 1
    if cache[row][col] == -1:
        cache[row][col] = 0
        for q, p in vector:
            m_y = row + q
            m_x = col + p
            if 0 <= m_y < n and 0 <= m_x < m:
                if paper[row][col] > paper[m_y][m_x]:
                    cache[row][col] += dfs(m_y, m_x)
    else:
        return cache[row][col]
    return cache[row][col]    

def solution():
    print(dfs(0, 0))

solution()