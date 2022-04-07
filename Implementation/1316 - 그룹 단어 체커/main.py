def words_cmp(words, idx):
    if (words[idx - 1] != words[idx]):
        for tmp in range(0, idx, 1):
            if words[tmp] == words[idx]:
                return False
    return True

def check_dup():
    n = int(input())
    cnt = 0
    for i in range(0, n, 1):
        words = input()
        if len(words) == 1:
            cnt += 1
            continue
        for j in range(1, len(words), 1):
            if not words_cmp(words, j):
                break
            elif j == len(words) - 1:
                cnt += 1
    return cnt

print(check_dup())