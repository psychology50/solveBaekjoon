import sys

input = sys.stdin.readline
INF = int(1e9)

n, e = map(int, input().split()) # 정점, 간선 개수

def get_smallest_node(distance, visited): # 방문하지 않는 노드 중에서 최단거리가 가장 짧은 노드 반환
    global n

    min_value = INF
    idx = 0
    for i in range(1, n+1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            idx = i
    return idx

def dijkstra(start, distance, visited, graph):
    global n

    distance[start] = 0 # 시작 노드
    visited[start] = True
    for j in graph[start]: # 출발 노드와 인접 노드에 대한 최단거리 테이블 갱신
        distance[j[0]] = j[1]

    for i in range(n-1): # 모든 노드에 대해 반복
        now = get_smallest_node(distance, visited) # 현재 최단 거리가 가장 짧은 노드를 꺼내어 방문처리
        visited[now] = True
        for j in graph[now]: # 선택된 노드와 연결된 다른 노드 확인
            cost = distance[now] + j[1] # 선택된 노드를 통해 가는 비용 다시 계산
            if cost < distance[j[0]]:
                distance[j[0]] = cost # 최단거리 테이블 갱신

def solution():
    global n, e
    
    k = int(input()) # 시작 정점 위치
    visited = [False] * (n+1) # 방문 체크
    distance = [INF] * (n+1)  # 최단 거리
    graph = [[] for _ in range(n+1)] # 간선 정보
    for _ in range(e):
        u, v, w = map(int, input().split())
        graph[u].append((v, w)) # u -> v 정점으로 이동하는 비용 w

    dijkstra(k, distance, visited, graph)

    for i in range(1, n+1): # 모든 노드로 가기 위한 최단 거리 출력
        if distance[i] == INF: # 도달할 수 없는 경우
            print("INF")
        else:
            print(distance[i])

solution()