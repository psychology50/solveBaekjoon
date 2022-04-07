cnt_w = 0
cnt_b = 0

def split(row, col, n, paper):
    global cnt_w
    global cnt_b

    color = paper[row][col]
    for y in range(row, row + n):
        for x in range(col, col + n):
            if (color != paper[y][x]):
                split(row, col, n//2, paper)
                split(row + n//2, col, n//2, paper)
                split(row, col + n//2, n//2, paper)
                split(row + n//2, col + n//2, n//2, paper)
                return
    if color == 0:
        cnt_w += 1
    else:
        cnt_b += 1

def solution():
    n = int(input())
    paper = [list(map(int, input().split())) for _ in range(n)]

    split(0, 0, n, paper)
    print(cnt_w)
    print(cnt_b)

solution()