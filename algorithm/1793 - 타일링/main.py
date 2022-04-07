cache = [0]*251

'''
def calc_case(n):
    if n <= 2:
        return cache[n]
    if cache[n] == 0:
        if n % 2 == 1:
            cache[n] = 2 * calc_case(n - 1) - 1
        elif n % 2 == 0:
            cache[n] = 2 * calc_case(n - 1) + 1
    return cache[n]
'''
def calc_case(n):
    if n <= 2:
        return cache[n]
    if cache[n] == 0:
        cache[n] = calc_case(n-2)*2 + calc_case(n-1)
    return cache[n]

def solution():
    cache[0] = 1
    cache[1] = 1
    cache[2] = 3
    while True:
        try:
            n = int(input())        
            print(calc_case(n))
        except:
            break

solution()