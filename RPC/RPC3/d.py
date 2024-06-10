from collections import deque

n = int(input())
a = deque([int(x) for x in input().split()])

c = 0
while len(a) > 1:
    while a[0] != a[-1]:
        if a[0] < a[-1]:
            aux = a.popleft()
            a[0] = a[0] + aux
        else:
            aux = a.pop()
            a[-1] = a[-1] + aux
        c += 1
    if len(a) >= 2:
        a.popleft()
        a.pop()

print(c)
