import sys
from collections import deque
input = sys.stdin.readline

def bfs(box, n, m):
    queue = deque()
    vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    visited = [[0]*m for _ in range(n)]
    for row in range(n):
        for col in range(m):
            if box[row][col] == 1:
                visited[row][col] = 1
                queue.append([row, col])
            if box[row][col] == -1:
                visited[row][col] = 1
    cnt = len(queue)
    ans = 0
                
    while queue:
        y, x = queue.popleft()        
        cnt -= 1
        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < n and 0 <= m_x < m:
                if not visited[m_y][m_x] and box[m_y][m_x] == 0:
                    queue.append([m_y, m_x])
                    visited[m_y][m_x] = 1
                elif not visited[m_y][m_x]:
                    visited[m_y][m_x] = 1
        if cnt == 0 and queue:
            ans += 1
            cnt = len(queue)
    for i in visited:
        for j in i:
            if j == 0:
                return -1
    return ans

def solution():
    m, n = map(int, input().split())
    box = [list(map(int, input().split())) for _ in range(n)]
    
    print(bfs(box, n, m))


solution()