import sys

input = sys.stdin.readline
sys.setrecursionlimit(2000)


def recur(person, work, who, lock):
    for w in work[person]:
        if who[w] == -1:
            who[w] = person
            return True
    for w in work[person]:
        if lock[w]:
            continue
        lock[w] = True
        if who[w] != person and recur(who[w], work, who, lock):
            lock[w] = False
            who[w] = person
            return True
    return False


def main(n, m, k, work):
    res = 0
    lock = [False] * (m + 1)
    who = [-1] * (m + 1)
    for person in range(n):
        if recur(person, work, who, lock):
            res += 1
    for person in range(n):
        now = 0
        while now < k and recur(person, work, who, lock):
            now += 1
        k -= max(now, 0)
        res += now
    print(res)


if __name__ == "__main__":
    N, M, K = list(map(int, input().split()))
    work_ = [list(map(int, input().split()))[1:] for _ in range(N)]
    main(N, M, K, work_)