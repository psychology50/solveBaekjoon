import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def dfs(idx, depth):
    visited[idx] = True
    d[idx] = depth

    for node in tree[idx]:
        if visited[node]:
            continue
        parent[node][0] = idx
        dfs(node, depth + 1)

def lca(a, b):
    if d[a] > d[b]:
        a, b = b, a

    for i in range(20, -1, -1): # dijkstra alogorithm
        if d[b] - d[a] >= 2**i:
            b = parent[b][i]
    
    if a == b: return a

    for i in range(20, -1, -1):
        if parent[a][i] != parent[b][i]:
            a = parent[a][i]
            b = parent[b][i]

    return parent[a][0]

def solution():
    m = int(input())

    dfs(1, 0) # parent info update
    for i in range(1, 21):
        for j in range(1, n+1):
            parent[j][i] = parent[parent[j][i-1]][i-1]

    for _ in range(m):
        a, b = map(int, input().split())
        print(lca(a, b))

if __name__ == "__main__":
    n = int(input())
    tree = [[] for _ in range(n+1)]
    parent = [[0]*21 for _ in range(n+1)]
    visited = [False] * (n+1)
    d = [0] * (n+1)

    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    solution()