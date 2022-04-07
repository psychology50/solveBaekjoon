import sys
read = sys.stdin.readline
maxAns = -1
def selectRegion(r, c):
    if r > 0 and c > 0:
        return 0
    if r > 0 and c <= 0:
        return 1
    if r <= 0 and c <= 0:
        return 2
    if r <=0 and c > 0:
        return 3
 
def cornerVal(n):
    temp = []
    m = (2*n+1)**2
    for i in range(4):
        temp.append(m - 2 * n * i)
    return temp
 
def cal(r, c):
    global maxAns
 
    case = selectRegion(r, c)
    bigger = max(abs(r), abs(c))
    corners = cornerVal(bigger)
 
    if case == 0:
        if abs(r) == bigger:        # (3,2)
            diff = bigger - abs(c)
            ans = corners[0] - diff
        else:                       # (2,3)
            diff = bigger - abs(r)
            ans = corners[3] - (2 * bigger) + diff
 
    elif case == 1:
        if abs(r) == bigger:        # (3,-2)
            diff = bigger - abs(c)
            ans = corners[1] + diff
        else:                       # (2,-3)
            diff = bigger - abs(r)
            ans = corners[1] - diff
 
    elif case == 2:
        if abs(r) == bigger:        # (-3,-2)
            diff = bigger - abs(c)
            ans = corners[2] - diff
        else:                       # (-2,-3)
            diff = bigger - abs(r)
            ans = corners[2] + diff
 
    else:
        if abs(r) == bigger:        # (-3,2)
            diff = bigger - abs(c)
            ans = corners[3] + diff
        else:                       # (-2,3)
            diff = bigger - abs(r)
            ans = corners[3] - diff
    if ans > maxAns:
        maxAns = ans
    return ans
 
r1, c1, r2, c2 = map(int, read().split())
 
R = r2-r1+1
C = c2-c1+1
D = [[0 for _ in range(C)] for _ in range(R)]
 
 
 
for i in range(R):
    for j in range(C):
        D[i][j] = str(cal(r1 + i, c1 + j))
strLen = len(str(maxAns))
 
 
for i in range(R):
    for j in range(C):
        temp = D[i][j]
        D[i][j] = ' ' * (strLen - len(temp))
        D[i][j] += temp
 
for d in D:
    for i in d:
        print(i, end = ' ')
    print()
