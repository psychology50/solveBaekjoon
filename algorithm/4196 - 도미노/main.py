import sys

sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

def dfs(node, graph, visited, queue:list):
    visited[node] = 1

    for next_node in graph[node]:
        if visited[next_node] == 0:
            dfs(next_node, graph, visited, queue)
    queue.append(node)

def make_queue(v, graph, visited):
    queue = []

    for node in range(1, v+1):
        if visited[node] == 0:
            dfs(node, graph, visited, queue)
    return queue

def reverse_dfs(node, graph, visited, graph_indegree, cnt):
    visited[node] = 1
    graph_indegree[node] = cnt

    for next_node in graph[node]:
        if visited[next_node] == 0:
            reverse_dfs(next_node, graph, visited, graph_indegree, cnt)

def check_ssc(queue:list, graph, visited, graph_indegree):
    cnt = 0

    while queue:
        node = queue.pop()
        if visited[node] == 0:
            cnt += 1
            reverse_dfs(node, graph, visited, graph_indegree, cnt)
    return cnt

def solution():  
    v, e = map(int, input().split())
    graph = [[] for _ in range(v+1)]
    rev_graph = [[] for _ in range(v+1)]
    visited = [0] * (v+1)

    for _ in range(e):
        a, b = map(int, input().split())
        graph[a].append(b)
        rev_graph[b].append(a)

    queue = make_queue(v, graph, visited)
    visited = [0] * (v+1) # visited reset
    graph_indegree = [0] * (v + 1)

    cnt = check_ssc(queue, rev_graph, visited, graph_indegree)
    scc_indegree = [0] * (cnt + 1) # scc 위상정렬

    for idx in range(1, v+1):
        for parent in graph[idx]:
            if not (graph_indegree[idx] == graph_indegree[parent]):
                scc_indegree[graph_indegree[parent]] += 1
                
    answer = 0
    for node in range(1, len(scc_indegree)):
        if scc_indegree[node] == 0:
            answer += 1
    print(answer)
        
t = int(input())
for _ in range(t):
    solution()