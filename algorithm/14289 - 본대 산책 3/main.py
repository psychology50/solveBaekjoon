import sys

input = sys.stdin.readline
MOD = 1000000007

def matrix_multiple(matrix1, matrix2):
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
    
    for key, value in graph.items(): # 한 번씩 이동
        for idx in value:
            cache1[key][idx] = 1
    for i in range(n):
        cache2[i][i] = 1

    while d > 0:
        if d % 2 == 1:
            cache2 = matrix_multiple(cache1, cache2)
            d -= 1
        cache1 = matrix_multiple(cache1, cache1)
        d //= 2
    return cache2[0][0] 

def solution():
    graph = {i : [] for i in range(n)}
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
        graph[b].append(a)
    d = int(input())
    print(work(graph, d))
    
if __name__ == '__main__':
    n, m = map(int, input().split())
    solution()