from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
c, e = map(int, input().split())
region = [[0]*n for _ in range(n)]
visited = [[0]*n for _ in range(n)]
vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def dfs(row, col, department):
    queue = deque()
    queue.append([row, col])
    if department == 1:
        cnt = c - 1
    else:
        cnt = e - 1
    region[row][col] = department
    visited[row][col] = 1

    while queue:
        y, x = queue.popleft()
        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < n and 0 <= m_x < n:
                if visited[m_y][m_x] == 0:
                    if cnt > 0:
                        queue.append([m_y, m_x])
                        region[m_y][m_x] = department
                        visited[m_y][m_x] = 1
                        cnt -= 1
                    else:
                        visited[m_y][m_x] = -1
    return cnt

def solution():
    if n == 1:
        print(-1)
        return

    case1 = dfs(0, 0, 1)
    case2 = dfs(n-1, n-1, 2)

    if not case1 == 0 or not case2 == 0:
        print(-1)
        return
    else:
        print(1)
    for i in region:
        print(*i, sep='')
    

solution()