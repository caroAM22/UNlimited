for _ in range(int(input())):
    n = int(input())
    a = list(input())
    b = list(input())
    ra = 0
    rb = 0
    for i in range(n):
        if int(a[i]) > int(b[i]):
            ra += 1
        elif int(a[i]) < int(b[i]):
            rb += 1
    if ra > rb:
        print("RED")
    elif ra < rb:
        print("BLUE")
    else:
        print("EQUAL")
