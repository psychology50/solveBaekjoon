def solution():
    n, m = map(int, input().split())
    board = [list(input()) for _ in range(n)]
    mbti = [('E', 'I'), ('N', 'S'), ('F', 'T'), ('J', 'P')]
    vector = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
    cnt = 0
    for row in range(n):
        for col in range(m):
            if board[row][col] in mbti[0]:
                for q, p in vector:
                    m_y = row + q
                    m_x = col + p
                    for i in range(1, 4):
                        if 0 <= m_y < n and 0 <= m_x < m:
                            if board[m_y][m_x] in mbti[i]:
                                m_y += q
                                m_x += p
                                if i == 3:
                                    cnt += 1
                                    break
                            else:
                                break
    print(cnt)
                
solution()