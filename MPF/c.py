x = {}
y = {}
a = 0
n = 0
while a == 0 and n < 4:
    x1, y1 = list(map(int, input().split()))
    if x1 in x:
        a = abs(x[x1] - y1)
    elif y1 in y:
        a = abs(y[y1] - x1)
    else:
        x[x1] = y1
        y[y1] = x1
    n += 1
print(a**2)
