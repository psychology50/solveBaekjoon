import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

n, e = map(int, input().split()) # 정점, 간선 개수

def dijkstra(start, distance, graph):
    global n

    heap = []
    heapq.heappush(heap, (0, start))
    distance[start] = 0
    
    while heap:
        dist, now = heapq.heappop(heap)
        if distance[now] < dist: # 예외 처리, 추가하려는 노드보다 짧은 노선이 이미 저장되어 있다면 패스
            continue
        for i in graph[now]: # 인접 노드 호출
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(heap, (cost, i[0]))

def solution():
    global n, e
    
    k = int(input()) # 시작 정점 위치
    distance = [INF] * (n+1)  # 최단 거리
    graph = [[] for _ in range(n+1)] # 간선 정보
    for _ in range(e):
        u, v, w = map(int, input().split())
        graph[u].append((v, w)) # u -> v 정점으로 이동하는 비용 w

    dijkstra(k, distance, graph)

    for i in range(1, n+1): # 모든 노드로 가기 위한 최단 거리 출력
        if distance[i] == INF: # 도달할 수 없는 경우
            print("INF")
        else:
            print(distance[i])

solution()