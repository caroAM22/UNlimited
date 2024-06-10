for _ in range(int(input())):
    n, a, b = list(map(int, input().split()))
    ass = a * n
    if n % 2 == 0:
        bs = b * (n // 2)
    else:
        bs = b * (n // 2) + a
    ans = min(ass, bs)
    print(ans)
