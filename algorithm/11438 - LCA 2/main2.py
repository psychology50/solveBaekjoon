import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(cur, pre):
    parent[cur] = pre # 현재 노드의 부모 노드 정보 업데이트
    size[cur] = 1 # 부트리 정점의 수 계산 

    for child in tree[cur]:
        if child == pre: # 부모 노드 제외
            continue
        size[cur] += dfs(child, cur) # 재귀 빠져나오면서 
    return size[cur]

def hld(cur, prev, chain_idx, depth):
    chain_depth[cur] = depth # 체인 구분
    belong_chain[cur] = chain_idx # 
    rel_pos_in_chain[cur] = len(chains[chain_idx]) # 현재 만들고 있는 체인 길이
    chains[chain_idx].append(cur) # 체인에 포함된 노드 업데이트

    max_idx = 0
    for child in tree[cur]:
        if child == prev:
            continue
        if size[child] > size[max_idx]:
            max_idx = child
    if max_idx != 0:
        hld(max_idx, cur, chain_idx, depth) # 현재 체인 확장
    for child in tree[cur]:
        if child == prev or child == max_idx:
            continue
        hld(child, cur, child, depth+1) # 새로운 체인 생성

def lca(a, b):
    while belong_chain[a] != belong_chain[b]: # 깊이 맞추기
        if chain_depth[a] > chain_depth[b]:
            a = parent[belong_chain[a]]
        else:
            b = parent[belong_chain[b]]
        
    if rel_pos_in_chain[a] > rel_pos_in_chain[b]:
        return b
    else:
        return a

def solution():
    m = int(input())

    dfs(1, 0) # parent info update
    hld(1, 0, 1, 0)

    for _ in range(m):
        a, b = map(int, input().split())
        print(lca(a, b))

if __name__ == "__main__":
    n = int(input())
    parent = [0] * (n+1)    # 각 노드의 부모 노드 info
    d = [0] * (n+1)         # 각 노드까지 깊이
    size = [0] * (n+1)
    tree = [[] for _ in range(n+1)]

    belong_chain = [-1] * (n+1)
    rel_pos_in_chain = [-1] * (n+1)
    chain_depth = [-1] * (n+1)
    chains = [[] for _ in range(n+1)]

    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    solution()