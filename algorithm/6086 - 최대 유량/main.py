import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 8)

def bfs(start, process, flow):
    queue = deque()
    queue.append(start)

    visited = [-1] * 128
    visited[start] = start

    while queue:
        idx = queue.popleft()
        for i in range(65, 123):
            if visited[i] == -1 and process[idx][i] - flow[idx][i] > 0:
                queue.append(i)
                visited[i] = idx
    return visited

def merge_pipe(process):
    start, end = 65, 90
    flow = [[0]*128 for _ in range(128)]
    result = 0

    while True:
        parent = bfs(start, process, flow)
        if parent[end] == -1:
            return result

        min_value = 2147483647

        idx = end
        while idx != start:
            min_value = min(min_value, process[parent[idx]][idx] - flow[parent[idx]][idx])
            idx = parent[idx]

        idx = end
        while idx != start:
            flow[parent[idx]][idx] += min_value
            flow[idx][parent[idx]] -= min_value
            idx = parent[idx]

        result += min_value

def solution():
    n = int(input())
    process = [[0]*128 for _ in range(128)]
    for _ in range(n):
        u, v, x = input().split()
        u = ord(u)
        v = ord(v)
        x = int(x)
        process[u][v] += x
        process[v][u] += x
    print(merge_pipe(process))

solution()