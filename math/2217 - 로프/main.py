def solution():
    cnt_rope = int(input())
    each_limit = []
    max_weight = []
    for _ in range(cnt_rope):
        each_limit.append(int(input()))

    each_limit.sort()
    for idx in range(cnt_rope):
        max_weight.append(each_limit[idx] * (cnt_rope - idx))
    print(max(max_weight))

solution()
