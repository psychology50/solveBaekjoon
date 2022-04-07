n = int(input())
s = list(map(int, input().split()))
#idx = 0
test = 0

'''
def is_valid(case):
    for tmp in range(idx):
        if case[tmp] == case[idx]:
            return False
    return True
'''

def fill_list(case, value, deepth):
    #global idx
    global test
    test += 1
    if deepth == n:
        return
    value += s[deepth]
    case.append(value)
    ''' time error. => set 자료형은 중복을 허용하지 않으니 마지막에 자료형 타입 변환?
    if is_valid(case):
        idx += 1
    else:
        case.pop()
    '''
    fill_list(case, value, deepth + 1)
    fill_list(case, value - s[deepth], deepth + 1)

'''
def in_result(result, nbr):
    for tmp in result:
        if nbr == tmp:
            return True
    return False
'''

def solution():
    case = []
    if n != len(s): exit()
    fill_list(case, 0, 0)
    #result = set(case)
    ''' time error. => 전체 비교가 아니라, 이미 존재하는 값을 이용해 결과를 도출하는 방법?
    for nbr in range(1, 2000001):
        if not in_result(result, nbr):
            print(nbr)
            return
    '''
    case = list(set(case))
    case.sort()
    case.append(0)
    for nbr in range(1, len(case) + 2):
        if nbr != case[nbr - 1]:
            print(test)
            #print(nbr)
            return
solution()