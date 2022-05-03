# 이분 매칭 90% 언저리에서 시간 초과..

import sys

input = sys.stdin.readline
INF = int(1e9)

def dfs(now, visited):
    if visited[now]:
        return False
    visited[now] = True
    
    for _next in adj[now]:
        if bMatch[_next] == False or dfs(bMatch[_next], visited):
            #aMatch[now] = _next
            bMatch[_next] = now
            return True
    return False

def solution():
    cnt = 0

    for start in range(1, n+1):
        visited = [False for _ in range(n+1)]
        if dfs(start, visited):
            cnt += 1

    print(cnt)

if __name__ == "__main__":
    n, m = map(int, input().split())
    adj = [[] for _ in range(n+1)] # adj[i][j] = Ai와 Bj가 이어져 있는가?
    for idx in range(1, n+1):
        graph = list(map(int, input().split()))[1:]
        for node in graph:
            adj[idx].append(node)

    #aMatch = [-1 for _ in range(n+1)] # group B와 연결된 정점 정보
    bMatch = [0 for _ in range(m+1)] # group A와 연결된 정점 정보

    solution()