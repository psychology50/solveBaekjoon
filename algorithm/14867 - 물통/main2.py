import sys
from collections import deque

input = sys.stdin.readline

def dfs(a, b, c, d):
    queue = deque()
    queue.append([0, 0])
    visited = {}
    visited[(0, 0)] = 0
    
    if c == 0 and d == 0:
        return 0

    while queue:
        y, x = queue.popleft()
        if visited.get((c, d)):
            return visited.get((c, d))

        if not visited.get((a, x)): # a 채우기
            visited[(a, x)] = visited[(y, x)] + 1
            queue.append([a, x])
        if not visited.get((y, b)): # b 채우기
            visited[(y, b)] = visited[(y, x)] + 1
            queue.append([y, b])
        if not visited.get((0, x)): # a 버리기
            visited[(0, x)] = visited[(y, x)] + 1
            queue.append([0, x])
        if not visited.get((y, 0)): # b 버리기
            visited[(y, 0)] = visited[(y, x)] + 1
            queue.append([y, 0])

        # a -> b
        if y <= b - x:
            if not visited.get((0 , x+y)):
                visited[(0, x+y)] = visited[(y, x)] + 1
                queue.append([0, x+y])
        else:
            if not visited.get((y-(b-x), b)):
                visited[(y-(b-x), b)] = visited[(y, x)] + 1
                queue.append([y-(b-x), b])
        # b -> a
        if x <= a - y:
            if not visited.get((y+x, 0)):
                visited[(y+x, 0)] = visited[(y, x)] + 1
                queue.append([y+x, 0])
        else:
            if not visited.get((a, x-(a-y))):
                visited[(a, x-(a-y))] = visited[(y, x)] + 1
                queue.append([a, x-(a-y)])

    return -1

def solution():
    a, b, c, d = map(int, input().split())
    print(dfs(a, b, c, d))

solution()