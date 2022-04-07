n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]
footprints = [[0] * m for _ in range(n)]
move = [(-1, 0), (0, 1), (1, 0), (0, -1)] # up right bottom left
result = 0

def dfs(row, col, deepth, total):
    global result
    if deepth == 4:
        result = max(result, total)
        return
    for m_r, m_c in move:
        tmp_r = row + m_r
        tmp_c = col + m_c
        if 0 <= tmp_r < n and 0 <= tmp_c < m and footprints[tmp_r][tmp_c] == 0:
            footprints[tmp_r][tmp_c] = 1
            dfs(tmp_r, tmp_c, deepth + 1, total + paper[tmp_r][tmp_c])
            footprints[tmp_r][tmp_c] = 0

def foku(row, col, total):
    global result
    min_branch = 10000
    branch = 0

    if row == 0 or row == n - 1 or col == 0 or col == m - 1:
        min_branch = 0
        branch += 1

    for m_r, m_c in move:
        tmp_r = row + m_r
        tmp_c = col + m_c
        if 0 <= tmp_r < n and 0 <= tmp_c < m:
            min_branch = min(min_branch, paper[tmp_r][tmp_c])
            total += paper[tmp_r][tmp_c]
            branch += 1

    if branch == 4:
        result = max(result, total - min_branch)

def solution():
    for row in range(n):
        for col in range(m):
            footprints[row][col] = 1
            dfs(row, col, 1, paper[row][col])
            footprints[row][col] = 0
            foku(row, col, paper[row][col])
            
    print(result)

solution()