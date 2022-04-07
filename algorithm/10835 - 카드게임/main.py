from collections import deque
import sys
input = sys.stdin.readline

def dfs(n, a, b, cache):
    queue = deque()
    queue.append([0, 0])
    cache[0][0] = 0
    vector = [(1, 0), (1, 1), (0, 1)]

    while queue:
        print(queue)
        left, right = queue.popleft()
        if left == n or right == n:
            continue
        for y, x in vector:
            m_y = left + y
            m_x = right + x
            if m_y <= n and m_x <= n:
                if a[left] <= b[right] and cache[left][right] > cache[m_y][m_x]:
                    if y == 0 and x == 1:
                        continue
                    else:
                        cache[m_y][m_x] = cache[left][right]
                        queue.append([m_y, m_x])
                if a[left] > b[right]:
                    if (y == 0 and x == 1):
                        if cache[left][right] + b[right] > cache[m_y][m_x]:
                            cache[m_y][m_x] = cache[left][right] + b[right]
                            queue.append([m_y, m_x])
                    elif cache[left][right] > cache[m_y][m_x]:
                        cache[m_y][m_x] = cache[left][right]
                        queue.append([m_y, m_x])

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    cache = [[-1]*(n+1) for _ in range(n+1)]
    
    dfs(n, a, b, cache)
    max_row = max(cache[n])
    max_col = 0
    for idx in range(n):
        max_col = max(max_col, cache[idx][n])
    print(max(max_row, max_col))

solution()