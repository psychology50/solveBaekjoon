n = int(input())
s = list(map(int, input().split()))

def fill_list(case, value, deepth):
    if deepth == n:
        return
    value += s[deepth]
    case.append(value)
    fill_list(case, value, deepth + 1)
    fill_list(case, value - s[deepth], deepth + 1)

def solution():
    case = []
    if n != len(s): exit()
    fill_list(case, 0, 0)
    case = list(set(case))
    case.sort()
    case.append(0)
    for nbr in range(1, len(case) + 1):
        if nbr != case[nbr - 1]:
            print(nbr)
            return
    
solution()
