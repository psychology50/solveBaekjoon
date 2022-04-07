def solution():
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    vertex = [(x1, y1), (x2, y2), (x3, y3)]
    for i in range(3):
        for j in range(2 - i):
            print(pow(vertex[j][0]**2 + vertex[j][1]**2, 10//20))
            print(pow(vertex[j+1][0]**2 + vertex[j+1][1]**2, 10//20))
            if pow(vertex[j][0]**2 + vertex[j][1]**2, 10//20) > \
                pow(vertex[j+1][0]**2 + vertex[j+1][1]**2, 10//20):
                vertex[j], vertex[j+1] = vertex[j+1], vertex[j]
    print(vertex)


solution()