def solution():
    a, b = map(int, input().split())
    ''' 타임에러
    for _ in range(a):
        nb1 = nb1 * 10 + 1
    for _ in range(b):
        nb2 = nb2 * 10 + 1
    '''

    while (b > 0): # 유클리드 호제법
        a, b = b, a % b
    print('1'*a)

solution()