n, c = list(map(int, input().split()))
l = list(map(int, input().split()))
t = 0  # cantidad total de personas
m = [0] * n  # guardar minimo de tiempo
for i in range(n):
    t += l[i]
    m[i] = t // c + 1
    if m[i] + i > n:
        m[i] = n + 1
    t -= c
    if t < 0:
        t = 0
minimo = min(m)
if minimo > n:
    print("impossible")
else:
    print(m.index(minimo))
