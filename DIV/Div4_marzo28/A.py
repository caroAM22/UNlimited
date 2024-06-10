n = int(input())
for i in range(n):
    a, b, c = list(map(int, input().split()))
    if a < b and b < c:
        print("STAIR")
    elif a < b and b > c:
        print("PEAK")
    else:
        print("NONE")
