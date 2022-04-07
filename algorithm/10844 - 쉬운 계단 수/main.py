def solution():
    n = int(input())
    cache = [[0]*10 for _ in range(n)]
    for idx in range(1, 10):
        cache[0][idx] = 1

    for i in range(1, n):
        for j in range(10):
            if j == 0:
                cache[i][j] = cache[i-1][1]
            elif j == 9:
                cache[i][j] = cache[i-1][8]
            else:
                cache[i][j] = cache[i-1][j-1] + cache[i-1][j+1]
    print(sum(cache[n - 1]) % 1000000000)

solution()