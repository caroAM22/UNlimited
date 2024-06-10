n = int(input())
a = list(map(int, input().split()))

if n <= 2:
    print(0)
else:
    maxi = max(a)
    b = a.copy()
    b.pop(a.index(maxi))
    maxi = max(b)
    flag = False
    con = 0
    c = 0
    for i in range(n):
        if not flag and a[i] >= maxi:
            flag = True
            c = 0
        elif flag and a[i] >= maxi:
            con = max(con, c)
            c = 0
        else:
            c += maxi - a[i]

    print(con)
