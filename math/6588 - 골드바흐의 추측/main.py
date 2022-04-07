def get_decimal(n):
    decimal = [True for i in range(n)]
    for i in range(2, 1001):
        if decimal[i]:
            for k in range(i + i, n, i):
                decimal[k] = False
    return decimal

def solution():
    decimal = get_decimal(1000001)
    while True:
        n = int(input())
        if n == 0:
            break
        
        flag = 0
        for i in range(3, len(decimal)):
            if decimal[i] and decimal[n - i]:
                print(f"{n} = {i} + {n - i}")
                flag = 1
                break
        if flag == 0:
            print("Goldbach's conjecture is wrong.")

solution()