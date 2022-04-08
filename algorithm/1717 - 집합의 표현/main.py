import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**8)

def search_node(idx, _set):
    if idx == _set[idx]:
        return idx
    return search_node(_set[idx], _set)

def union(a, b, _set):
    node1 = search_node(a, _set)
    node2 = search_node(b, _set)

    if node1 == node2:
        return
    if node1 > node2:
        _set[node2] = node1
    else:
        _set[node1] = node2

def solution():
    n, m = map(int, input().split())
    _set = [i for i in range(n+1)]

    for _ in range(m):
        flag, a, b = map(int, input().split())
        if flag == 0:
            union(a, b, _set)
        else:
            if search_node(a, _set) == search_node(b, _set):
                print("YES")
            else:
                print("NO")

solution()