# 2,147,483,647 2,147,483,647 1 을 감당할 수 있는가?

''' 1 try
def solution():
    a, b, c = map(int, input().split())
    for _ in range(b):
        a *= a
    print(a % c)
'''

''' 2 try
def solution():
    a, b, c = map(int, input().split())
    print(pow(a, b) % c)
'''

def high_speed_pow(a, b, c):
    if b == 0:
        return 1
    value = high_speed_pow(a, b // 2, c)
    if b % 2 == 0:
        return (value ** 2) % c
    else:
        return ((value ** 2) * a) % c

def solution():
    a, b, c = map(int, input().split())
    ans = high_speed_pow(a, b, c)
    print(ans)

solution()