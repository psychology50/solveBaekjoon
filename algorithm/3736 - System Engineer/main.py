import sys
import re
from collections import deque

sys.setrecursionlimit(10**8)

input = sys.stdin.readline
INF = int(1e9)

def bfs():
    queue = deque()
    for idx in range(n):
        if not matched[idx]: # 매칭 안 되어 있으면 level = 0
            level[idx] = 0
            queue.append(idx)
        else:
            level[idx] = INF

    while queue: # level 측정
        now = queue.popleft()
        for nxt in adj[now]: # server에 연결된 server(=nxt) 중에서
            if s[nxt] != -1 and level[s[nxt]] == INF: # server는 매칭이 안 되어 있고, 그 server가 연결된 job은 매칭이 되어 있는 상태라면
                level[s[nxt]] = level[now] + 1 # level 1씩 증가
                queue.append(s[nxt])

def dfs(node):
    for next_node in adj[node]: # job의 node번째에 연결된 next_node 중에
        if s[next_node] == -1 or (level[s[next_node]] == level[node]+1 and dfs(s[next_node])):
            # 매칭이 안 되었거나, 매칭은 됐는데 next_node의 level이 node보다 1 큰 경우
            matched[node] = 1
            j[node] = next_node
            s[next_node] = node
            return 1
    return 0

def solution():
    cnt = 0

    while True:
        flow = 0
        bfs()
        for i in range(n):
            if not matched[i]:
                if dfs(i):
                    flow += 1
        if flow == 0:
            break
        cnt += flow
    print(cnt)

if __name__ == "__main__":
    while True:
        try:
            n = int(input())
            adj = [[] for _ in range(n)]
            for _ in range(n):
                tmp = list(input().split())
                job = int(re.sub(r'[^0-9]', '', tmp[0]))
                server = int(re.sub(r'[^0-9]', '', tmp[1]))
                for idx in range(server):
                    adj[job].append(int(tmp[2+idx]))
            
            matched = [0 for _ in range(10000)] # 매칭 여부 판단
            j = [-1 for _ in range(10000)] # 어떤 server와 매칭되어있는가?
            s = [-1 for _ in range(20000)] # 어떤 job과 매칭되어 있는가?
            level = [INF for _ in range(10000)] # job 정점 레벨

            solution()
        except:
            break