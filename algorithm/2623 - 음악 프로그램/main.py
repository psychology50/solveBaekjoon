import sys
from collections import deque

input = sys.stdin.readline

def solution():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    indegree = [0] * (n+1)
    result = []

    for i in range(m):
        _input = list(map(int, input().split())) # _input[0] : 정점, 그 외에는 모두 이동 가능한 곳
        for j in range(1, _input[0]):
            graph[_input[j]].append(_input[j+1])
            indegree[_input[j+1]] += 1 # 정점을 기준으로 이동할 곳에 진입 차수 1증가

    queue = deque()

    for i in range(1, n+1):    
        if indegree[i] == 0:
            queue.append(i)
        
    while queue:
        tmp = queue.popleft()
        result.append(tmp)
        for i in graph[tmp]:
            indegree[i] -= 1
            if indegree[i] == 0:
                queue.append(i)
    
    if len(result) != n:
        print(0)
        return

    for i in result:
        print(i)

    


solution()