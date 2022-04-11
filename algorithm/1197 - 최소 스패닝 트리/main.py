import sys

input = sys.stdin.readline

def find(a, node):
    if a == node[a]:
        return a
    return find(node[a], node)

def union(a, b, node):
    a = find(a, node)
    b = find(b, node)

    if a > b:
        node[b] = a
    elif a <= b:
        node[a] = b


def solution():
    v, e = map(int, input().split())
    tree = [i for i in range(v+1)]
    cost = []
    result = 0

    for _ in range(e):
        a, b, c = map(int, input().split())
        cost.append((c, a, b))
    cost.sort()

    for value in cost:
        c, a, b = value
        if find(a, tree) != find(b, tree):
            union(a, b, tree)
            result += c
    print(result)

solution()