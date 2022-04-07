import sys
from collections import deque

input = sys.stdin.readline

def dfs(a, b, c, d):
    queue = deque()
    queue.append([0, 0])
    visited = [[-1]*(b+1) for _ in range(a+1)]
    visited[0][0] = 0

    while queue:
        y, x = queue.popleft()
        if visited[c][d] != -1:
            return visited[c][d]

        if visited[a][x] == -1: # a 채우기
            visited[a][x] = visited[y][x] + 1
            queue.append([a, x])
        if visited[y][b] == -1: # b 채우기
            visited[y][b] = visited[y][x] + 1
            queue.append([y, b])
        if visited[0][x] == -1: # a 버리기
            visited[0][x] = visited[y][x] + 1
            queue.append([0, x])
        if visited[y][0] == -1: # b 버리기
            visited[y][0] = visited[y][x] + 1
            queue.append([y, 0])

        # a -> b
        if y <= b - x:
            if visited[0][x+y] == -1:
                visited[0][x+y] = visited[y][x] + 1
                queue.append([0, x+y])
        else:
            if visited[y-(b-x)][b] == -1:
                visited[y-(b-x)][b] = visited[y][x] + 1
                queue.append([y-(b-x), b])
        # b -> a
        if x <= a - y:
            if visited[y+x][0] == -1:
                visited[y+x][0] = visited[y][x] + 1
                queue.append([y+x, 0])
        else:
            if visited[a][x-(a-y)] == -1:
                visited[a][x-(a-y)] = visited[y][x] + 1
                queue.append([a, x-(a-y)])

    return -1

def solution():
    a, b, c, d = map(int, input().split())
    print(dfs(a, b, c, d))

solution()