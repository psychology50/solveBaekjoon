import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**7)

def dfs(idx, visited, barn, caw):
    if visited[idx] == True:
        return 0
    visited[idx] = True

    for favor in caw[idx]:
        if barn[favor] == 0 or dfs(barn[favor], visited, barn, caw):
            barn[favor] = idx
            return True
    return False
    
def solution():
    n, m = map(int, input().split())
    caw = [[] for _ in range(n+1)]
    barn = [0]*(m+1)

    for i in range(1, n+1):
        caw[i] = list(map(int, input().split()))[1:]
    for i in range(1, n+1):
        visited = [False]*(n+1)
        dfs(i, visited, barn, caw)
    cnt = 0
    for i in barn:
        if i > 0:
            cnt += 1
    print(cnt)

solution()