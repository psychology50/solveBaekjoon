def solution():
    n, l, r = map(int, input().split())
    
    legend = [[[0]*101 for _ in range(101)] for _ in range(101)]
    legend[1][1][1] = 1

    for height in range(2, n+1):
        for left in range(1, l+1):
            for right in range(1, r+1):
                legend[height][left][right] = (legend[height-1][left][right-1] + legend[height-1][left-1][right] + (legend[height-1][left][right])*(height-2)) % 1000000007
    print(legend[n][l][r])

solution()