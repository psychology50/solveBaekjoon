import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 8)

n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]

def calc_size_tree(n):
    tmp = 1
    while tmp < n:
        tmp <<= 1
    tmp <<= 1

    return tmp

def create_tree(left, right, idx, seg_tree):
    if left == right:
        seg_tree[idx] = arr[left]
        return seg_tree[idx]

    mid = (left + right) // 2
    seg_tree[idx] = create_tree(left, mid, idx*2+1, seg_tree) + create_tree(mid+1, right, idx*2+2, seg_tree)
    return seg_tree[idx]

def update_tree(left, right, idx, b, c, seg_tree):
    if b < left or right < b:
        return
    
    seg_tree[idx] += c

    if left == right:
        return

    mid = (left + right) // 2
    update_tree(left, mid, idx*2+1, b, c, seg_tree)
    update_tree(mid+1, right, idx*2+2, b, c, seg_tree)

def calc_sum(left, right, idx, b, c, seg_tree):
    if left > c or right < b:
        return 0
    
    if b <= left and right <= c:
        return seg_tree[idx]

    mid = (left + right) // 2
    return calc_sum(left, mid, idx*2+1, b, c, seg_tree) + calc_sum(mid+1, right, idx*2+2, b, c, seg_tree)

def solution():
    seg_tree = [0] * calc_size_tree(n)
    create_tree(0, len(arr)-1, 0, seg_tree)

    for _ in range(m+k):
        a, b, c = map(int, input().split())
        if a == 1:
            update_tree(0, n-1, 0, b-1, c - arr[b-1], seg_tree)
            arr[b-1] = c
        else:
            print(calc_sum(0, n-1, 0, b-1, c-1, seg_tree))

solution()