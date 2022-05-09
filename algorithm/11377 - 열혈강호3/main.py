import sys
from collections import deque

# 이유는 모르겠지만 실패 ㅠㅠ 나중에 다시 해보자...

input = sys.stdin.readline
sys.setrecursionlimit(10**8)
INF = int(1e9)

def bfs():
    queue = deque()

    for node in range(1, n+1):
        if len(aMatch[node]) < 2:
            level[node] = 0
            queue.append(node)
        else:
            level[node] = INF
    level[0] = INF

    while queue:
        node = queue.popleft()
        if level[node] < level[0]:
            for nxt_node in adj[node]:
                if level[bMatch[nxt_node]] == INF:
                    level[bMatch[nxt_node]] = level[node] + 1
                    queue.append(bMatch[nxt_node])
    return level[0] != INF

def dfs(now): 
    if now:
        for node in adj[now]:
            if level[bMatch[node]] == level[now] + 1 and dfs(bMatch[node]):
                aMatch[now].append(node)
                bMatch[node] = now
                return 1
        level[now] = INF
        return 0
    return 1

def solution():
    global k
    cnt = 0

    while bfs():
        for idx in range(1, n+1):
            if len(aMatch[idx]) == 0:
                cnt += dfs(idx)

    while bfs():
        print(cnt)
        for idx in range(1, n+1):
            if len(aMatch[idx]) < 2:
                cnt += dfs(idx)
            if len(aMatch[idx]) < 2:
                cnt += dfs(idx)
            k -= 1
            if k == 0:
                print(cnt)
                return

    print(cnt)

if __name__ == "__main__":
    n, m, k = map(int, input().split())
    adj = [[]]
    for idx in range(1, n+1):
        adj.append(list(map(int, input().split()))[1:])

    aMatch = [[] for _ in range(n+1)]
    bMatch = [0 for _ in range(m+1)]
    level = [INF for _ in range(n+1)]

    solution()