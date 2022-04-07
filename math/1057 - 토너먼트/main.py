import math

def solution():
    n, kim, im = map(int, input().split())
    num = [i for i in range(1, n + 1)]
    flag = 0
    round = 1

    for i in range(math.ceil(n / 2)):
        if (min(kim, im) + 1 == max(kim, im)) and (min(kim, im) + 1) % 2 == 0:
            print(round)
            flag = 1
            break
        kim = (kim + 1) // 2 if kim % 2 == 1 else kim // 2
        im = (im + 1) // 2 if im % 2 == 1 else im // 2
        round += 1
        
    if flag == 0:
        print(-1)

solution()