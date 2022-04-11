import sys

input = sys.stdin.readline

def find(num, node):
    if num == node[num]:
        return num
    return find(node[num], node)

def union(a, b, node):
    a = find(a, node)
    b = find(b, node)

    if a > b:
        node[a] = b
    elif a <= b:
        node[b] = a

def solution():
    n, m = map(int, input().split())
    parent = [i for i in range(n+1)]
    cost = []
    result = 0

    for _ in range(m):
        a, b, c = map(int, input().split())
        cost.append((c, a, b))
    cost.sort()
    
    for value in cost:
        c, a, b = value
        if find(a, parent) != find(b, parent):
            union(a, b, parent)
            result += c
            max_cost = c

    print(result - max_cost)
        

solution()