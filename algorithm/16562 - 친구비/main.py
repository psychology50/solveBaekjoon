import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def find(num, tree):
    if num == tree[num]:
        return num
    return find(tree[num], tree)

def union(a, b, tree, cost):
    a = find(a, tree)
    b = find(b, tree)

    if a == b:
        return
    else:
        if cost[a] > cost[b]:
            tree[a] = b
        else:
            tree[b] = a

def solution():
    n, m, k = map(int, input().split())
    cost = [0] + list(map(int, input().split()))
    relation = [i for i in range(n+1)]
    for _ in range(m): # friend relation create
        a, b = map(int, input().split())
        union(a, b, relation, cost)

    result = 0
    for idx, root in enumerate(relation):
        if idx == root:
            result += cost[idx]
    
    if result <= k:
        print(result)
    else:
        print("Oh no")

solution()