cache = [0] * 31

def solution():
    n = int(input())
    cache[2], cache[4] = 3, 11
    if n % 2 == 1:
        print(0)
        return
    
    for i in range(6, 31, 2):
        cache[i] = cache[i - 2] * cache[2]
        for j in range(4, i, 2):
            cache[i] += 2 * cache[i - j]
        cache[i] += 2
    print(cache[n])
    
solution()