from collections import deque
import sys
input = sys.stdin.readline

def dfs(n, cache, schedule):
    queue = deque()
    queue.append([0, 0])
    cache[0][0] = 0
    
    while queue:
        day, coupon = queue.popleft()
        for voucher in range(1, 6, 2):
            tomorrow = day + voucher
            if tomorrow > n: # 범위를 벗어나는 경우 종료
                break

            if voucher == 1:
                if tomorrow in schedule: # 못 가는 날
                    if cache[day][coupon] < cache[tomorrow][coupon]:
                        cache[tomorrow][coupon] = cache[day][coupon]
                        queue.append([tomorrow, coupon])
                    continue
                if coupon >= 3: # 쿠폰을 쓰는 경우
                    if cache[day][coupon] < cache[tomorrow][coupon-3]:
                        cache[tomorrow][coupon-3] = cache[day][coupon]
                        queue.append([tomorrow, coupon-3])
                if cache[day][coupon] + 10000 < cache[tomorrow][coupon]: # 안 쓰는 경우
                    cache[tomorrow][coupon] = cache[day][coupon] + 10000
                    queue.append([tomorrow, coupon])
            if voucher == 3:
                if cache[day][coupon] + 25000 < cache[tomorrow][coupon+1]:
                    cache[tomorrow][coupon+1] = cache[day][coupon] + 25000
                    queue.append([tomorrow, coupon+1])
            if voucher == 5:
                if cache[day][coupon] + 37000 < cache[tomorrow][coupon+2]:
                    cache[tomorrow][coupon+2] = cache[day][coupon] + 37000
                    queue.append([tomorrow, coupon+2])
            

def solution():
    n, m = map(int, input().split())
    cache = [[2147483647]*41 for _ in range(n+1)]
    if m == 0:
        schedule = []
    else:
        schedule = list(map(int, input().split()))

    dfs(n, cache, schedule)
    print(min(cache[n]))

solution()