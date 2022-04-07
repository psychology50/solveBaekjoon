def solution():
    for _ in range(4):
        x1, y1, p1, q1, x2, y2, p2, q2 = map(int, input().split())
        if y1 > q2 or q1 < y2 or x1 > p2 or p1 < x2: # overlab
            print("d")
        else:
            if p1 == x2 or x1 == p2:
                if q1 == y2 or y1 == q2:
                    print("c")
                else:
                    print("b")
            elif q1 == y2 or y1 == q2:
                print("b")
            else:
                print("a")

solution()