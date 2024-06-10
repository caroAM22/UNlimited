a, b, c = list(map(int, input().split()))
mb = a // b
mc = a // c
f = 0
for i in range(1, mb + 1):
    for j in range(1, mc + 1):
        if a == ((i * b) + (j * c)):
            f = 1
            break
    if f == 1:
        break
print(f)
