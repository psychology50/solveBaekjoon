import sys
from collections import deque

input = sys.stdin.readline
INF = int(1e9)

# 호프크로프트 카프 전용 bfs 함수 : 특정 그룹의 각 정점에 레벨 매김 (이 경우엔 A그룹)
def bfs():
    queue = deque()

    for node in range(1, n+1):
        if len(aMatch[node]) < 2: # 매칭 개수가 2개가 아니면 level 0으로 시작
            level[node] = 0
            queue.append(node)
        else:
            level[node] = INF
    level[0] = INF

    while queue: # group A의 각 정점에 0, 1, 2, 3, ...의 레벨을 매김
        node = queue.popleft()
        if level[node] < level[0]: # 아직 level 갱신이 안 됐을 때
            for nxt_node in adj[node]: # 현재 접근 중인 노드의 간선 정보 접근
                if level[bMatch[nxt_node]] == INF:
                    level[bMatch[nxt_node]] = level[node] + 1
                    queue.append(bMatch[nxt_node])
    return level[0] != INF

# 호프크로프트 카프 전용 dfs 함수 : 새 매칭을 찾아내면 true
def dfs(now): 
    if now:
        for node in adj[now]: # Agroup의 now번 째 노드와 연결된 Bgroup의 node중에 매칭이 안 되었거나,
            if level[bMatch[node]] == level[now] + 1 and dfs(bMatch[node]): # node에 연결된 now'과 now 레벨 차가 1밖에 안 나거나,
                aMatch[now].append(node) # node에 연결된 now'이 매칭되지 않았거나, level이 1 차이 나는 경우에
                bMatch[node] = now
                return 1
        level[now] = INF
        return 0
    return 1


def solution():
    cnt = 0

    while bfs():
        for idx in range(1, n+1):
            if len(aMatch[idx]) < 2: # 매칭 개수가 2개 안 넘으면
                cnt += dfs(idx)
            if len(aMatch[idx]) < 2:
                cnt += dfs(idx)
    print(cnt)

if __name__ == "__main__":
    n, m = map(int, input().split())
    adj = [[]] # adj[i][j] = Ai와 Bj가 이어져 있는가?
    for idx in range(1, n+1):
        adj.append(list(map(int, input().split()))[1:])

    aMatch = [[] for _ in range(n+1)] # group B와 연결된 정점 정보
    bMatch = [0 for _ in range(m+1)] # group A와 연결된 정점 정보

    level = [INF for _ in range(n+1)] # group A의 각 정점의 level

    solution()

