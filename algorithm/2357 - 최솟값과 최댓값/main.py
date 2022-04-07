''' 
def solution():
    n, m = map(int, input().split()) # 1 <= N <= 100,000, 1 <= M <= 100,000
    squence = [0]
    for _ in range(n):
        squence.append(int(input()))
    
    for _ in range(m):
        a, b = map(int, input().split())
        print(min(squence[a:b+1]), max(squence[a:b+1]))
'''
# 시간 초과가 나는 이유? 값을 저장하고 무식하게 조회하려니 그러겠지..
# 저장할 때, 다른 방법을 쓰면 조회가 빨라지나? -> 이진트리

import sys

sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

n, m = map(int, input().split()) # 1 <= N <= 100,000, 1 <= M <= 100,000
sequence = []
for _ in range(n):
    sequence.append(int(input()))

def fill_seg(left, right, idx, arr):
    if left == right:
        arr[idx] = (sequence[left], sequence[right])
        return arr[idx]

    mid = (left + right) // 2

    left = fill_seg(left, mid, idx * 2 + 1, arr)
    right = fill_seg(mid + 1, right, idx * 2 + 2, arr)

    arr[idx] = (min(left[0], right[0]), max(left[1], right[1]))
    
    return arr[idx]


def search_tree(left, right, idx, a, b, arr):
    if a > right or b < left:
        return (1000000001, 0)

    if a <= left and right <= b:
        return arr[idx]

    mid = (left + right) // 2

    left = search_tree(left, mid, idx * 2 + 1, a, b, arr)
    right = search_tree(mid + 1, right, idx * 2 + 2, a, b, arr)

    return (min(left[0], right[0]), max(left[1], right[1]))
    

def solution():    
    size_node = 1
    while size_node < n:
        size_node <<= 1
    size_node <<= 1
    seg_tree = [0]*size_node

    fill_seg(0, n-1, 0, seg_tree)

    for _ in range(m):
        a, b = map(int, input().split())
        print(" ".join(map(str, search_tree(0, n-1, 0, a-1, b-1, seg_tree))))


solution()