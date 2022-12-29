import sys

sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

def reverse_graph(v, graph):
    rev_graph = [[] for _ in range(v+1)]

    for i in range(1, v+1):
        for j in graph[i]:
            rev_graph[j].append(i)
    return rev_graph

def dfs(node, graph, visited, queue:list):
    visited[node] = 1

    for next_node in graph[node]:
        if visited[next_node] == 0:
            #queue.append(next_node)
            dfs(next_node, graph, visited, queue)
    queue.append(node)

def make_queue(v, graph, visited):
    queue = []

    for node in range(1, v+1):
        if visited[node] == 0:
            dfs(node, graph, visited, queue)
    return queue

def reverse_dfs(node, graph, visited, scc:list):
    visited[node] = 1
    scc.append(node)

    for next_node in graph[node]:
        if visited[next_node] == 0:
            reverse_dfs(next_node, graph, visited, scc)

def check_ssc(queue:list, graph, visited):
    cnt, result = 0, []

    while queue:
        scc = []
        node = queue.pop()
        if visited[node] == 0:
            reverse_dfs(node, graph, visited, scc)
            result.append(sorted(scc))
            cnt += 1
    result.sort()
    return cnt, result

def solution():
    v, e = map(int, input().split())
    graph = [[] for _ in range(v+1)]
    visited = [0] * (v+1)

    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)

    queue = make_queue(v, graph, visited)
    graph = reverse_graph(v, graph)
    visited = [0] * (v+1)
    cnt, result = check_ssc(queue, graph, visited)

    print(cnt)
    for i in result:
        for j in i:
            print(j, end=" ")
        print(-1)

solution()