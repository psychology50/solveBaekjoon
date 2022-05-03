import sys

input = sys.stdin.readline
MOD = 1000000007

def matrix_multiple(matrix1, matrix2): # 행렬 곱
    tmp = [[0]*(n) for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                tmp[i][j] += matrix1[i][k] * matrix2[k][j]
                tmp[i][j] %= MOD
    return tmp

def work(graph:dict, d): 
    cache1 = [[0]*(n) for _ in range(n)] 
    cache2 = [[0]*(n) for _ in range(n)] 
    
    for key, value in graph.items(): # [출발 노드][도착 노드] = 경우의 수
        for idx in value:
            cache1[key][idx] = 1
    for i in range(n):
        cache2[i][i] = 1 # 단위 행렬 & 각 건물에서 제자리 위치인 경우

    while d > 0: # 분할 정복 : 행렬을 이동횟수만큼 거듭제곱했을 때 [1][1]의 경우의 수가 답
        if d % 2 == 1: # 이동횟수가 홀수인 경우에 진행된 만큼 cache2를 갱신시키고 이동횟수 1 감소.
            cache2 = matrix_multiple(cache1, cache2) 
            d -= 1
        cache1 = matrix_multiple(cache1, cache1) # cache1로 계속 이동
        d //= 2 # 행렬을 제곱함으로써 이동횟수는 반감된다.
    return cache2[0][0] 

def solution():
    graph = {i : [] for i in range(n)} # 노드 간선 연결
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a-1].append(b-1)
        graph[b-1].append(a-1)
    d = int(input())
    print(work(graph, d))
    
if __name__ == '__main__':
    n, m = map(int, input().split())
    solution()