def check_bracket(bracket, stack):
    flag, value, total = 0, 1, 0

    for i in bracket:
        if stack[-1] == '(' and i == ')':
            if flag == 1:
                total += value
                flag = 0
            value //= 2
            stack.pop()
        elif stack[-1] == '[' and i == ']':
            if flag == 1:
                total += value
                flag = 0
            value //= 3
            stack.pop()
        else:
            stack.append(i)
            if i == '(':
                value *= 2
                flag = 1
            elif i == '[':
                value *= 3
                flag = 1

    if len(stack) != 1: # 최종적으로 stack에 '0'만 존재해야 한다.
        return 0
    else:
        return total

def solution():
    bracket = input()
    stack = ['0']
    result = check_bracket(bracket, stack)
    print(result)

solution()