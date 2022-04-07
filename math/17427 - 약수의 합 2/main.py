def solution():
    n = int(input())
    result = 0
    
    for current in range(1, n + 1):
        ''' O(n루트n) -> time error
        square = int(pow(current, (1.0/2.0)))
        for i in range(1, square + 1):
            if current % i == 0:
                result += i
                if i != current // i:
                    result += current // i
        '''
        # n // current : 개수
        result += current * (n//current)
    print(result)

solution()