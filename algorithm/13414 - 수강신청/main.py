import sys
input = sys.stdin.readline

''' 큐로 구현 -> 뭔가 오류날 거 같은 느낌??? -> 시간초과!!
from collections import deque
def solution():
    k, l = map(int, input().split())
    section = deque()
    for _ in range(l):
        id = int(input())
        if id in section:
            section.remove(id)
        section.append(id)
    for _ in range(k):
        print(section.popleft())
'''

# 딕셔너리 자료구조로 구현
def solution():
    k, l = map(int, input().split())
    section = {}
    for number in range(l): # 중복 key가 있다면 기존 값 제거
        section[input().rstrip()] = number

    section = sorted(section.items(), key=lambda x: x[1])
    cnt = 0
    for key in section:
        if cnt == k:
            break
        print(key[0])
        cnt += 1

solution()