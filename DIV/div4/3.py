from math import sqrt

for _ in range(int(input())):
    n = int(input())
    l = sum(list(map(int, input().split())))
    x = round(sqrt(l))
    if (x**2) == l:
        print("YES")
    else:
        print("NO")
