import sys

input = sys.stdin.readline

def lis_func(left, right, current, stack):
    while left < right:
        mid = (left + right) // 2

        if stack[mid] < current:
            left = mid + 1
        else:
            right = mid
    return right

def solution():
    n = int(input())
    a = list(map(int, input().split()))
    lis = [[0, 0] for _ in range(n)]
    stack, result = [], []
    
    lis[0][0], lis[0][1] = 0, a[0]
    stack.append(a[0])

    for idx in range(1, n):
        lis[idx][1] = a[idx]

        if stack[-1] < a[idx]:
            lis[idx][0] = len(stack)
            stack.append(a[idx])
        else:
            position = lis_func(0, len(stack)-1, a[idx], stack)
            lis[idx][0] = position
            stack[position] = a[idx]
    print(len(stack))

    max_length = len(stack) - 1
    for i in range(len(lis)-1, -1, -1):
        if lis[i][0] == max_length:
            result.append(lis[i][1])
            max_length -= 1
        if max_length == -1:
            break

    print(*result[::-1])


solution()