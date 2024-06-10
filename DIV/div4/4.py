c = {"b", "c", "d"}
v = {"a", "e"}
for _ in range(int(input())):
    n = int(input())
    l = list(input())
    i = 0
    y = []
    while i < n:
        if i + 3 > n:
            x = l[i : i + 2]
        elif i + 2 > n:
            x = l[i]
        else:
            x = l[i : i + 3]
        if len(x) == 3 and x[0] in c and x[1] in v and x[2] in c:
            if (i + 3) != n and l[(i + 3)] in v:
                y.append(x[0] + x[1])
                i += 2
            else:
                y.append(x[0] + x[1] + x[2])
                i += 3
        elif len(x) == 1:
            y.append(x)
            i += 1
        else:
            y.append(x[0] + x[1])
            i += 2
    print(".".join(y))
