def solution():
    n = int(input())
    value = list(map(int, input().split()))
    min_value = []

    total = 0
    if n == 1:
        value.sort()
        total = sum(value[:5])
    else:
        min_value.append(min(value[0], value[5]))
        min_value.append(min(value[1], value[4]))
        min_value.append(min(value[2], value[3]))
        min_value.sort()

        total += min_value[0] * (5 * n**2 - 16*n + 12) # 1면
        total += sum(min_value[:2]) * (8 * n - 12) # 2면
        total += sum(min_value[:3]) * 4 # 3면
    print(total)

solution()