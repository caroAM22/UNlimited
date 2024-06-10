n = int(input())
for _ in range(n):
    n, k = map(int, input().split())
    num = [str(j) for j in range(n, 0, -1)]
    num1 = []
    for i in range(k, n):
        num1.append(num[i])
    for i in range(k - 1, -1, -1):
        num1.append(num[i])
    print(" ".join(num1))
