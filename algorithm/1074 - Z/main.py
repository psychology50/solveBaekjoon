n, r, c = map(int, input().split())
cnt = 0

def divide_recursive(row, col, limit):
    global cnt
    if row == r and col == c:
        print(cnt)
        exit(0)
    if limit == 1:
        cnt += 1
        return
    if (row <= r < row + limit and col <= c < col + limit):
        divide_recursive(row, col, limit//2)
        divide_recursive(row, col + limit//2, limit//2)
        divide_recursive(row + limit//2, col, limit//2)
        divide_recursive(row + limit//2, col + limit//2, limit//2)
        return
    else:
        cnt += pow(limit, 2)
        return

def solution():
    global n
    divide_recursive(0, 0, pow(2, n))
    

solution()