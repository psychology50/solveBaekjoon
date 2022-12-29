import sys
sys.setrecursionlimit(100100)
sys_input = sys.stdin.readline
sys_print = sys.stdout.write


n = int(input())

node = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, sys_input().split())
    node[a].append(b)
    node[b].append(a)

sub_size = [0 for _ in range(n+1)]
parent = [0 for _ in range(n+1)]
def dfs_size(cur, prev):
    parent[cur] = prev
    sub_size[cur] = 1
    for child in node[cur]:
        if child == prev:
            continue
        sub_size[cur] += dfs_size(child, cur)
    return sub_size[cur]

dfs_size(1, 0)

belong_chain = [-1 for _ in range(n+1)]
rel_pos_in_chain = [-1 for _ in range(n+1)]
chain_depth = [-1 for _ in range(n+1)]
chains = [[] for _ in range(n+1)]

def hld(cur, prev, chain_idx, depth):
    chain_depth[cur] = depth
    belong_chain[cur] = chain_idx
    rel_pos_in_chain[cur] = len(chains[chain_idx])
    chains[chain_idx].append(cur)

    max_idx = 0
    for child in node[cur]:
        if child == prev:
            continue
        if sub_size[child] > sub_size[max_idx]:
            max_idx = child
    if max_idx != 0:
        hld(max_idx, cur, chain_idx, depth)  # extend current chain
    for child in node[cur]:
        if child == prev or child == max_idx:
            continue
        hld(child, cur, child, depth+1)  # make new chain

hld(1, 0, 1, 0)

def lca(a, b):
    while belong_chain[a] != belong_chain[b]:
        if chain_depth[a] > chain_depth[b]:
            a = parent[belong_chain[a]]
        else:
            b = parent[belong_chain[b]]
    if rel_pos_in_chain[a] > rel_pos_in_chain[b]:
        return b
    else:
        return a

m = int(sys_input())
for _ in range(m):
    a, b = map(int, sys_input().split())
    sys_print(f'{lca(a, b)}\n')