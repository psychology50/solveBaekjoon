import sys
from collections import deque

input = sys.stdin.readline
INF = int(1e9)

def updateEdge(u, v, x): # u, v 정점, x 유량
    adj[u].append(v)
    adj[v].append(u)
    cost[u][v], cost[v][u] = x, 0
    flow[u][v], flow[v][u] = 0, 0

def dfs():
    result = 0

    while True:
        parent = [-1]*(size)
        queue = deque()
        queue.append(source)

        while queue:
            pre = queue.popleft()
            for now in adj[pre]:
                if parent[now] == -1 and cost[pre][now] - flow[pre][now] > 0:
                    queue.append(now)
                    parent[now] = pre

        if parent[sink] == -1: break

        idx = sink
        while idx != source:
            flow[parent[idx]][idx] += 1
            flow[idx][parent[idx]] -= 1
            idx = parent[idx]
        result += 1
    return result

def solution():
    if (n == 1 and m == 1) or abs(sy - ty) + abs(sx - tx) == 1: # exeption handling
        print(-1) # K와 H가 맞닿아 있는 경우 제거
        return

    for i in range(n*m): # 정점 in, out 분리 후 서로 연결
        updateEdge(2*i, 2*i+1, 1)

    current = 0
    for row in range(n): # 인접 인덱스에 장애물이 없다면 유량 MAX
        for col in range(m):
            if row + 1 < n and graph[row][col] != '#' and graph[row+1][col] != '#':
                _next = current + 2 * m
                updateEdge(current+1, _next, INF)
                updateEdge(_next+1, current, INF)
            if col + 1 < m and graph[row][col] != '#' and graph[row][col+1] != '#':
                _next = current + 2
                updateEdge(current+1, _next, INF)
                updateEdge(_next+1, current, INF)
            current += 2
    return print(dfs())
    
if __name__ == "__main__":
    n, m = map(int, input().split())
    size = 2*n*m
    graph = [[] for _ in range(n)]   # 원본
    adj = [[] for _ in range(size)]  # 정점 연결 정보
    cost = [{} for _ in range(size)] # 각 간선의 최대 유량
    flow = [{} for _ in range(size)] # 실제로 흐르는 유량
    cnt = 0

    for row in range(n):
        graph[row] += list(input().rstrip())
        for col in range(m):
            if graph[row][col] == 'K':
                sy, sx = row, col
                source = cnt + 1
            elif graph[row][col] == 'H':
                ty, tx = row, col
                sink = cnt
            cnt += 2

    solution()