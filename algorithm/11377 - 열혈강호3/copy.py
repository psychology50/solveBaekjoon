import sys
input = lambda: sys.stdin.readline().rstrip()
mis = lambda: map(int, input().split())

from collections import deque

def bfs():
    global level
    level = [-1] * N
    q = deque([SRC])
    level[SRC] = 0
    while q:
        cur = q.popleft()
        for nxt in g[cur]:
            if level[nxt] == -1 and capacity[cur][nxt] > flow[cur][nxt]:
                level[nxt] = level[cur] + 1
                q.append(nxt)
    return level[SNK] != -1

def dfs(cur, d, f):
    if cur == d or f == 0:
        return f
    for i in range(idx[cur], len(g[cur])):
        nxt = g[cur][i]
        if level[nxt] == level[cur] + 1 and capacity[cur][nxt] > flow[cur][nxt]:
            d_flow = dfs(nxt, d, min(capacity[cur][nxt] - flow[cur][nxt], f))
            if d_flow > 0:
                flow[cur][nxt] += d_flow
                flow[nxt][cur] -= d_flow
                return d_flow
        idx[cur] += 1
    return 0

INF = float('inf')
N, M, K = mis()
orig_N = N
N += M+3

capacity = [[0] * N for _ in range(N)]
flow = [[0] * N for _ in range(N)]
g = [[] for _ in range(N)]
level = [-1] * N
idx = [0] * N
SRC = 0; SNK = N-1

g[0].append(1)
g[1].append(0)
capacity[0][1] = K

for i in range(orig_N):
    g[0].append(i+2)
    g[i+2].append(0)
    capacity[0][i+2] += 1
    #capacity[i+2][0] += 1

    g[1].append(i+2)
    g[i+2].append(1)
    capacity[1][i+2] += 1
    #capacity[i+2][1] += 1
    # connect SRC-ppl, K-ppl

for i in range(orig_N+2, orig_N+M+2):
    g[i].append(SNK)
    g[SNK].append(i)
    capacity[i][SNK] += 1
    #capacity[SNK][i] += 1
    # connect work-SNK

for i in range(2, 2+orig_N):
    a, *t = mis()
    for work in t:
        work -= 1
        work += orig_N+2
        g[i].append(work)
        g[work].append(i)
        capacity[i][work] += 1
        #capacity[work][i] += 1
    # connect ppl-work
ans = 0
while bfs():
    idx = [0] * N
    while 1:
        cur_flow = dfs(SRC, SNK, INF)
        if not cur_flow:
            break
        ans += cur_flow
print(ans)