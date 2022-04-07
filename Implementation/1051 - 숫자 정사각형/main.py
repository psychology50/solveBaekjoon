def solution():
    n, m = map(int, input().split())
    board = [list(map(int, input())) for _ in range(n)]
    square = [[1]*m for _ in range(n)]

    for row in range(n):
        for col in range(m):
            vertex = board[row][col]
            idx = min(n - row - 1, m - col - 1)
            while idx > 0:
                if board[row][col + idx] == vertex and board[row + idx][col] == vertex \
                    and board[row + idx][col + idx] == vertex and square[row][col] < (idx + 1) ** 2:
                    square[row][col] = (idx + 1) ** 2
                idx -= 1
    print(max(map(max, square)))
    
solution()