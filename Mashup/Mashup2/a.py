n, m = list(map(int, input().split()))
t = list(map(int, input().split()))
b = list(map(int, input().split()))

t.remove(max(t))

result = max(t) * max(b)

print(result)
