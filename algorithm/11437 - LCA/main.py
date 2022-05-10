import sys

sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def dfs(idx, depth):
    visited[idx] = True
    d[idx] = depth

    for node in tree[idx]:
        if visited[node]:
            continue
        parent[node] = idx
        dfs(node, depth+1)

def lca(a, b):
    while d[a] != d[b]: # 깊이 맞추기
        if d[a] > d[b]:
            a = parent[a]
        else:
            b = parent[b]
        
    while a != b: # 같아질 때까지 동시에 부모 노드 탐색
        a = parent[a]
        b = parent[b]

    return a

def solution():
    m = int(input())

    dfs(1, 0) # parent info update

    for _ in range(m):
        a, b = map(int, input().split())
        print(lca(a, b))

if __name__ == "__main__":
    n = int(input())
    parent = [0] * (n+1)    # 각 노드의 부모 노드 info
    d = [0] * (n+1)         # 각 노드까지 깊이
    visited = [0] * (n+1)
    tree = [[] for _ in range(n+1)]

    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    solution()