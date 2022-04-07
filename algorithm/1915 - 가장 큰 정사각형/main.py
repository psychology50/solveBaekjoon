import sys

input = sys.stdin.readline

n, m = map(int, input().split())
board = [list(map(int, input().rstrip())) for _ in range(n)]
histogram = [[0]*(m+2) for _ in range(n)]
max_length = 0

def make_histogram():
    for col in range(1, m+1):
        cnt = 0
        for row in range(n):
            if board[row][col-1] == 1:
                cnt += 1
            else:
                cnt = 0
            histogram[row][col] = cnt

def search_square():
    global max_length
    
    stack = []

    for row in range(n):
        stack.append([-1, 0])
        col = 1
        while col < m+2:
            if stack[-1][1] < histogram[row][col]:
                stack.append([col-1, histogram[row][col]])
            elif stack[-1][1] > histogram[row][col]:
                y = stack[-1][1]
                stack.pop()
                x = stack[-1][0]
                
                if col - x - 2 > y:
                    length = y
                else:
                    length = col - x - 2

                if max_length < length:
                    max_length = length
                continue
            else:
                stack.pop()
                stack.append([col-1, histogram[row][col]])

            col += 1
        stack.clear()

def solution():
    global max_length

    make_histogram()
    search_square()

    print(pow(max_length, 2))
    return

solution()