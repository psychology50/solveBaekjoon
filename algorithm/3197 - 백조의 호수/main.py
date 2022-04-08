import sys
from collections import deque

input = sys.stdin.readline

r, c = map(int, input().split())
swan = []
vector = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def bfs(lake, visited, q_swan:deque):
    next_swan = deque()

    while q_swan:
        y, x = q_swan.popleft()

        if y == swan[1][0] and x == swan[1][1]:
            return True, None

        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < r and 0 <= m_x < c:
                if not visited[m_y][m_x]:
                    visited[m_y][m_x] = 1
                    if lake[m_y][m_x] == "X":
                        next_swan.append([m_y, m_x])
                    else:
                        q_swan.append([m_y, m_x])
    return False, next_swan

def melt(water:deque, lake):
    queue = deque()
    while water:
        y, x = water.popleft()
        for q, p in vector:
            m_y = y + q
            m_x = x + p
            if 0 <= m_y < r and 0 <= m_x < c:
                if lake[m_y][m_x] == 'X':
                    queue.append([m_y, m_x])
                    lake[m_y][m_x] = '.'
    return queue


def solution():
    water = deque()
    lake = []

    for row in range(r):
        new_line = list(input().rstrip())
        for idx, col in enumerate(new_line):
            if col == ".":
                water.append([row, idx])
            if col == "L":
                water.append([row, idx])
                swan.append([row, idx])
        lake.append(new_line)
    
    visited = [[0]*c for _ in range(r)]
    q_swan = deque()

    q_swan.append([swan[0][0], swan[0][1]])
    visited[swan[0][0]][swan[0][1]] = 1
    day = 0
    
    while True:
        is_valid, q_swan = bfs(lake, visited, q_swan)
        if is_valid:
            print(day)
            break
        water = melt(water, lake)
        day += 1 
    
solution()