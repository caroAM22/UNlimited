a = list(input())
b = list(input())

b.reverse()
r1 = []
r1.append(a.pop(0))
r2 = []
r2.append(b.pop(0))
v1 = ""
v2 = ""
vowels = set(["a", "e", "i", "o", "u"])

i = 0
while i < len(a):
    r1.append(a[i])
    if a[i] in vowels:
        v1 = r1.pop()
        break
    i += 1

i = 0
while i < len(b):
    r2.append(b[i])
    if b[i] in vowels:
        v2 = r2.pop()
        break
    i += 1

conector = []
if v2 != "":
    conector.append(v2)
elif v1 != "":
    conector.append(v1)
else:
    conector.append("o")

r2.reverse()
sol = r1 + conector + r2

print("".join(sol))
