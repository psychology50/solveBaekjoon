import heapq
import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    heap = []
    for _ in range(n):
        x = int(input())
        if x == 0:
            try:
                print(heapq.heappop(heap)[1])
            except:
                print(0)
        else:
            heapq.heappush(heap, (-x, x))

solution()