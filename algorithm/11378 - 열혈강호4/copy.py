import sys
from collections import deque, defaultdict

input = sys.stdin.readline


def bfs():
    for i in range(size):
        level[i] = -1

    level[0] = 0
    q = deque()
    q.append(0)

    while q:
        node  = q.popleft()

        for next in graph[node]:
            if level[next] == -1 and c[node][next] - f[node][next] > 0:
                level[next] = level[node] + 1
                q.append(next)

    return level[-1] != -1


def dfs(node, flows):
    global k
    if node == size - 1:
        return flows

    z = work[node]
    while z < len(graph[node]):
        next = graph[node][z]

        if level[next] == level[node] + 1 and c[node][next] - f[node][next] > 0:
            r = dfs(next, min(flows, c[node][next] - f[node][next]))

            if r > 0:
                f[node][next] += r
                f[next][node] -= r

                work[node] = z
                return r

        z += 1

    work[node] = z
    return 0


n, m, k = map(int, input().split())
size = n + m + 3

c = [[0] * size for _ in range(size)]
f = [[0] * size for _ in range(size)]

graph = defaultdict(list)

for i in range(1, 1+n):
    graph[0].append(i)
    graph[i].append(0)

    c[0][i] = 1

for i in range(1, 1+n):
    graph[size-2].append(i)
    graph[i].append(size-2)

    c[size-2][i] = 10000

c[0][size-2] = k
graph[0].append(size-2)
graph[size-2].append(0)

for i in range(1, 1+n):
    w = deque(map(int, input().split()))

    num = w.popleft()
    for j in range(num):
        c[i][n+w[j]] = 1

        graph[i].append(n+w[j])
        graph[n+w[j]].append(i)

for i in range(n+1, size-2):
    c[i][size-1] = 1

    graph[i].append(size-1)
    graph[size-1].append(i)

level = [-1] * size
result = 0

while bfs():
    work = [0] * size

    while True:
        flow = dfs(0, 10000)
        if flow == 0:
            break
        result += flow

print(result)