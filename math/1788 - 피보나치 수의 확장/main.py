cache = [0, 1, 1]

'''
def fibonacci(n):
    if n <= 2:
        return 1
    if cache[n] == 0:
        cache[n] = fibonacci(n - 2) + fibonacci(n - 1)
    return cache[n]
'''

def solution():
    n = int(input())
    cache[1], cache[2] = 1, 1

    if n < 0 and n % 2 == 0:
        print(-1)
    elif n == 0:
        print("0\n0")
        return
    else:
        print(1)

    for idx in range(3, abs(n) + 1):
        cache.append((cache[idx - 2] + cache[idx - 1]) % 1000000000)
    print(cache[abs(n)])

solution()