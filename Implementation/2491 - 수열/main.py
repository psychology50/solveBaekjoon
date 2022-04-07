def read_sequence(sequence, n, max_a, max_d):
    ascending, decending = 0, 0

    for idx in range(n):
        if sequence[idx - 1] < sequence[idx]:
            ascending += 1
            max_d = max(max_d, decending)
            decending = 1
        elif sequence[idx - 1] > sequence[idx]:
            decending += 1
            max_a = max(max_a, ascending)
            ascending = 1
        else:
            ascending += 1
            decending += 1
        max_a = max(max_a, ascending)
        max_d = max(max_d, decending)
    return max_a, max_d

def solution():
    n = int(input())
    sequence = list(map(int, input().split()))
    max_a, max_d = 1, 1

    if n == 1:
        print(1)
        return
    max_a, max_d = read_sequence(sequence, n, max_a, max_d)
    print(max(max_a, max_d))

solution()