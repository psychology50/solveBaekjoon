'''
def solution():
    r1, c1, r2, c2 = map(int, input().split())
    board = [[0]*(c2 - c1 + 1) for _ in range(r2 - r1 + 1)]
    size = (c2 - c1 + 1) * (r2 - r1 + 1)
    move_row, move_col = [0, -1, 0, 1], [1, 0, -1, 0]
    num, cnt, limit, tmp = 0, 0, 1, 0
    row, col = 0, 0

    while size > 0:
        cnt += 1
        num += 1
        if r1 <= row <= r2 and c1 <= col <= c2:
            board[row - r1][col - c1] = num
            size -= 1
        row += move_row[tmp]
        col += move_col[tmp]

        if cnt == limit:
            cnt = 0
            tmp += 1
            if tmp % 2 == 0:
                limit += 1
            if tmp % 4 == 0:
                tmp = 0
        
    for idx in range(len(board)):
        print(" ".join(map(str, board[idx])))
'''

def solution():
    r1, c1, r2, c2 = map(int, input().split())
    board = [[0]*(c2 - c1 + 1) for _ in range(r2 - r1 + 1)]
    size = (c2 - c1 + 1) * (r2 - r1 + 1)
    move_row, move_col = [0, -1, 0, 1], [1, 0, -1, 0]
    outermost = min(abs(r1), abs(c1), abs(r2), abs(c2))
    cnt = 0
    if outermost == 0 or outermost - 1 == 0 or (r1 < 0 < r2 and c1 < 0 < c2):
        num = 0
        row, col = 0, 0
        limit, tmp = 1, 0
    else:
        num = 1
        for position in range(1, outermost, 1):
            num += 8 * position
        row, col = outermost - 1, outermost
        limit, tmp = 2 * outermost - 1, 1

    while size > 0:
        cnt += 1
        num += 1
        if r1 <= row <= r2 and c1 <= col <= c2:
            board[row - r1][col - c1] = num
            size -= 1
            max_length = num
        row += move_row[tmp]
        col += move_col[tmp]

        if cnt == limit:
            cnt = 0
            if tmp == 1 or tmp == 3:
                limit += 1
            tmp = (tmp + 1) % 4

    for i in range(len(board)):
        for j in range(len(board[i])):
            print("{:>{}}".format(str(board[i][j]), len(str(max_length))), end = ' ')
        print()

solution()