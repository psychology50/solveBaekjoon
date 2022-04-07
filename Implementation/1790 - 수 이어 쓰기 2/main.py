def solution():
    n, k = map(int, input().split())
    digit = 1
    cnt = 9
    result = 0

    while k > digit * cnt:
        k -= digit * cnt
        result += cnt
        digit += 1
        cnt *= 10
    result += ((k - 1) // digit) + 1
    if result > n:
        print(-1)
    else:
        print(str(result)[(k - 1) % digit])

solution() 