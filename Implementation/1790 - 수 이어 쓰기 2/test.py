'''
[1] first : time error
def solution():
    n, k = map(int, input().split())
    tmp = []
    for i in range(1, n + 1):
        tmp.append(str(i))
    nbr = "".join(tmp)
    if (k > len(nbr)):
        print("-1")
        return
    print(nbr[k - 1])
'''

'''
[2] second : 너무나 당연하게도 time error..자릿수에 따라 경우의 수를 나눈다면?
def solution():
    n, k = map(int, input().split())
    nbr = ""
    for i in range(1, n + 1):
        nbr += (str(i))     // 문자열 이어 붙이려는 시도 자체가 문제.
        if len(nbr) >= k:   // 범위가 10억임. Do not try ㄴㄴ
            print(nbr[k - 1])
            return
''' 
def solution():
    n, k = map(int, input().split())
    #total_length = 0
    digit = 1
    cnt = 9
    result = 0

    while k > digit * cnt:
        k -= digit * cnt
        #total_length += digit * cnt
        result += cnt
        digit += 1
        cnt *= 10
    result += ((k - 1) // digit) + 1
    if result > n:
        print(-1)
    else:
        print(str(result)[(k - 1) % digit])

solution() 