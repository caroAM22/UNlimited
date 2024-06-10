n = int(input())
for i in range(n):
    a = int(input())
    c = 0
    for j in range(a * 2):
        if c >= 2:
            for k in range(a):
                if k % 2 == 1:
                    print("##", end="")
                else:
                    print("..", end="")
            if c == 3:
                c = 0
            else:
                c += 1
        else:
            for k in range(a):
                if k % 2 == 0:
                    print("##", end="")
                else:
                    print("..", end="")
            c += 1
        print()
