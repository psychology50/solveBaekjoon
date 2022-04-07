def solution():
    n = int(input())
    friends = [list(input()) for _ in range(n)]
    famous = [[0]*n for _ in range(n)]
    answer = 0

    for k in range(n): # 경유점
        for row in range(n): # 출발점
            for col in range(n): # 종착점
                if row == col:
                    continue
                if friends[row][col] == 'Y' or (friends[row][k] == 'Y' and friends[k][col] == 'Y'):
                    famous[row][col] = 1
    for idx in famous:
        answer = max(answer, sum(idx))
    print(answer)

solution()