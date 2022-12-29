'''
1. 가능한 경로와 경로상의 최소 유량 찾기
   (1) bfs (에드몬드 카프 알고리즘)
   (2) 탐색조건: 현재 flow가 해당 간선의 최대 flow를 넘지 않았는가?
                visited가 갱신되지 않았는가? -> 종점이 아니라면 큐 탈출
   (3) 최소유량: 경로상에 있는 간선의 용량 중 가장 작은 것을 택한다.
2. 현재 상태를 업데이트
   (1) 가장 작은 유량을 찾아서 전체 유량 수정
   (2) 이때, 역순으로 흐르는 방향은 -값으로 수정해야 한다.
       => 경로의 순서에 따라 최대로 흐르지 않았음에도 불구하고 끝나버리기 때문이다. 
3. 더이상 가능한 경로가 존재하지 않을 때까지 반복한다.
'''

import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 8)

def bfs(start, process, flow):
    queue = deque()
    queue.append(start)

    visited = [-1] * 128
    visited[start] = start

    while queue:
        idx = queue.popleft()
        for i in range(65, 123):
            if visited[i] == -1 and process[idx][i] - flow[idx][i] > 0:
                queue.append(i)
                visited[i] = idx
    return visited

def merge_pipe(process):
    start, end = 65, 90
    flow = [[0]*128 for _ in range(128)]
    result = 0

    while True:
        parent = bfs(start, process, flow)

        if parent[end] == -1:
            return result

        min_value = 2147483647

        idx = end
        while idx != start:
            min_value = min(min_value, process[parent[idx]][idx] - flow[parent[idx]][idx])
            idx = parent[idx]
        
        idx = end
        while idx != start:
            flow[parent[idx]][idx] += min_value
            flow[idx][parent[idx]] -= min_value
            idx = parent[idx]

        result += min_value

def solution():
    n = int(input())
    process = [[0]*128 for _ in range(128)]
    for _ in range(n):
        u, v, x = input().split()
        u = ord(u)
        v = ord(v)
        x = int(x)
        process[u][v] += x
        process[v][u] += x
    print(merge_pipe(process))

solution()