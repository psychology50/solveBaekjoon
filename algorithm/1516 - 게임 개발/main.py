import sys
from collections import deque

input = sys.stdin.readline

def solution():
    n = int(input())
    parent = [[0]*(n+1) for i in range(n+1)]
    is_valid = [0]*(n+1)
    time = [0]*(n+1) 
    queue = deque()

    for idx in range(1, n+1):
        _input = list(map(int, input().split()))
        time[idx] = _input[0]
        for value in _input[1:-1]:
            if value != -1:
                parent[idx][value] = 1
                is_valid[idx] += 1
        if is_valid[idx] == 0: # 따로 선행 조건이 없다면 큐에 삽입
            queue.append(idx)

    while queue:
        building = queue.popleft()
        tmp = 0
        for idx in range(1, n+1):
            if parent[idx][building] == 1: # 해당 건물을 선행조건으로 갖는 건물 탐색
                #parent[idx][building] = 0 => 선행 건물의 시간을 못 끌고 옴,,건드리면 ㄴㄴ
                is_valid[idx] -= 1
                if is_valid[idx] == 0:
                    queue.append(idx)
            
            if parent[building][idx] == 1: # 0으로 안 바뀌었으면 선행 건물의 시간 가져오기
                tmp = max(time[idx], tmp)
        time[building] += tmp

    for i in time[1:]:
        print(i)

solution()