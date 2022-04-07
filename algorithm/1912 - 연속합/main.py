def solution():
    n = int(input())
    sequence = list(map(int, input().split()))
    current, result = 0, sequence[0]

    for new in sequence:
        if current < 0:
            current = new
        else:
            current += new

        if result < current:
            result = current
    print(result)

solution()