import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    lis = [0]

    for current in a: # O(n)
        if lis[-1] < current:
            lis.append(current)
        else: # lis 값 갱신
            left = 0
            right = len(lis)

            while left < right: # O(log n) : 분할 탐색
                mid = (left + right) // 2

                if lis[mid] < current:
                    left = mid + 1
                else:
                    right = mid
            lis[right] = current
    print(len(lis) - 1)


solution()