def solution():
    n = int(input()) # 액자 수  1 <= n <= 20
    candidate = int(input()) # 전체 학생의 추천 수 <= 1000
    vote = list(map(int, input().split())) # 추천한 후보 1 <= x <= 100
    result = []
    cnt = []

    for i in vote:
        if i in result:
            cnt[result.index(i)] += 1
        else:
            if len(result) >= n:
                idx = cnt.index(min(cnt))
                del result[idx]
                del cnt[idx]
            result.append(i)
            cnt.append(1)

    result.sort()
    print(' '.join(map(str, result)))

solution()