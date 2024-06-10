for _ in range(int(input())):
    n, k = map(int, input().split())
    l1 = list(input().split())
    l = list(input().split())
    l2 = [0]
    for i in range(n):
        l2.append(l2[i] + int(l1[i]))
    c = 1
    mayor = 0
    m = 0
    while c < n + 1:
        prefix = l2[c] - l2[0]
        f = k - c
        if f < 0:
            break
        m = max(m, int(l[c - 1]))
        total = f * m + prefix
        mayor = max(total, mayor)
        c += 1
    print(mayor)
