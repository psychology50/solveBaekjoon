r1, c1, r2, c2 = map(int, input().split())
board = [[0]*(c2 - c1 + 1) for _ in range(r2 - r1 + 1)] # 최종 출력 리스트
max_length = 0 # 가장 큰 숫자 길이

def check_quadrant(row, col):
    if row > 0 and col >= 0: # 4사분면
        return 4
    if row >= 0 and col <= 0: # 3사분면
        return 3
    if row <= 0 and col <= 0: # 2사분면
        return 2
    if row <= 0 and col >= 0: # 1사분면
        return 1

def get_value_vertex(outermost):
    tmp = []
    num = 1
    for position in range(1, outermost + 1, 1):
        num += 8 * position
    for i in range(4):
        tmp.append(num - (2 * outermost * i)) # 해당 영역의 각 꼭짓점 값 도출
    return tmp

def fill_board(row, col):
    global max_length
    outermost = max(abs(row), abs(col)) # 영역의 위치를 지배하는 좌표로 확인
    quadrant = check_quadrant(row, col) # 해당 row, col 좌표가 몇 사분면에 위치하는가?
    vertex = get_value_vertex(outermost)

    if quadrant == 1:
        if outermost == abs(row):
            temp = outermost - abs(col)
            value = vertex[3] + temp
        else:
            temp = outermost - abs(row)
            value = vertex[3] - temp
    elif quadrant == 2:
        if outermost == abs(row):
            temp = outermost - abs(col)
            value = vertex[2] - temp
        else:
            temp = outermost - abs(row)
            value = vertex[2] + temp
    elif quadrant == 3:
        if outermost == abs(row):
            temp = outermost - abs(col)
            value = vertex[1] + temp
        else:
            temp = outermost - abs(row)
            value = vertex[1] - temp
    else:
        if outermost == abs(row):
            temp = outermost - abs(col)
            value = vertex[0] - temp
        else:
            temp = outermost - abs(row)
            value = vertex[3] - 2 * outermost + temp
    max_length = max(max_length, value)
    return value

def solution():
    global max_length
    for row in range(r2 - r1 + 1):
        for col in range(c2 - c1 + 1):
            board[row][col] = fill_board(r1 + row, c1 + col)

    for i in range(len(board)):
        for j in range(len(board[i])):
            print("{:>{}}".format(str(board[i][j]), len(str(max_length))), end = ' ')
        print()

solution()