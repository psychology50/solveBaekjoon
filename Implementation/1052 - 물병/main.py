def solution():
    n, k = map(int, input().split())
    total, tmp = 0, 1

    while True:
        num, cnt = n, 0
        while True: # 1개수 판단
            if num & 1:
                cnt += 1
            if num == 0 or num == 1:
                break
            num >>= 1

        if cnt <= k:
            print(total)
            return

        while True:
            if n & tmp != 0:
                n += tmp
                total += tmp
                break
            tmp <<= 1
        

solution()