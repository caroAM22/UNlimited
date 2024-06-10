n, m, k = list(map(int, input().split()))
l = list(map(int, input().split()))

l.sort(reverse=True)
t = round(sum(l[: m + k]) / sum(l) * 100, 9)
print(t)
