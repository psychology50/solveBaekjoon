move = [(-1, 0), (0, 1), (1, 0), (0, -1)]

def bfs(table, row, col):
    queue = [(0, 0)]
    time = 0

    while queue:
        visited = [[0]*col for _ in range(row)]
        cnt = 0
        for y, x in queue:
            if not visited[y][x]:
                visited[y][x] = 1
                for q, p in move:
                    m_y = y + q
                    m_x = x + p
                    if 0 <= m_y < row and 0 <= m_x < col:
                        if table[m_y][m_x] == 0:
                            queue.append((m_y, m_x))
                        else:
                            table[m_y][m_x] = 0
                            visited[m_y][m_x] = 1
                            cnt += 1
        if cnt == 0:
            return time, result
        else:
            result = cnt
            time += 1
            queue.clear()
            queue = [(0, 0)]

def solution():
    row, col = map(int, input().split())
    table = [list(map(int, input().split())) for _ in range(row)]
    
    time, cnt = bfs(table, row, col)
    print(time)
    print(cnt)

solution()