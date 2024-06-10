for i in range(int(input())):
    a, b, c = input().split()
    if a == b:
        print(c)
    elif b == c:
        print(a)
    elif c == a:
        print(b)
