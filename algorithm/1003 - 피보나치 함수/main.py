cache = [[0]*2 for _ in range(41)]

def fibonacci(n):
    if n <= 1:
        return cache[n]
    if cache[n][0] == 0 or cache[n][1] == 0:
        cache[n][0] = fibonacci(n - 2)[0] + fibonacci(n - 1)[0]
        cache[n][1] = fibonacci(n - 2)[1] + fibonacci(n - 1)[1]
    return cache[n]

def solution():
    t = int(input())
    cache[0][0], cache[0][1] = 1, 0
    cache[1][0], cache[1][1] = 0, 1
    
    for _ in range(t):
        n = int(input())
        if n == 0:
            print("1 0")
        elif n == 1:
            print("0 1")
        else:
            fibonacci(n)
            print(f"{cache[n][0]} {cache[n][1]}")
    
solution()