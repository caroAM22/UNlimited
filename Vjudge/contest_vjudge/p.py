from collections import deque

for _ in range(int(input())):
    n = input()
    flag = True
    stack = deque()

    for i in n:
        if i == "(" or i == "[":
            stack.append(i)
        elif stack:
            if i == ")" and stack and stack[-1] == "(":
                stack.pop()
            elif i == "]" and stack and stack[-1] == "[":
                stack.pop()
            else:
                flag = False
                break
        else:
            flag = False
            break

    if not stack and flag:
        print("Yes")
    else:
        print("No")
