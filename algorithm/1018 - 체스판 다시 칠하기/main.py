def main():
    row, col = map(int, input().split())
    board = [[0]*col for _ in range(row)]
    cnt = []

    for i in range(0, row):
        board[i] = input()
    for i in range(0, row - 7):
        for j in range(0, col - 7):
            idx_w = 0
            idx_b = 0
            for min_i in range(i, i + 8):
                for min_j in range(j, j + 8):
                    if (min_i + min_j) % 2 == 0:
                        if board[min_i][min_j] != 'W': # white 시작하는 경우
                            idx_w += 1
                        else:
                            idx_b += 1
                    else:
                        if board[min_i][min_j] != 'B':
                            idx_w += 1
                        else:
                            idx_b += 1
            cnt.append(min(idx_w, idx_b))
    print(min(cnt))

main()