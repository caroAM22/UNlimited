n = int(input())
x = input()
a = []
for e in x:
    a.append(e)

i = 1
while i < len(a):
    if a[i - 1] == "(" and a[i] == ")":
        a.insert(i, "1")
        i += 1
    elif a[i - 1] == ")" and a[i] == "(":
        a.insert(i, "*")
        i += 1
    elif a[i - 1] == ")" and a[i] == ")":
        a.insert(i, "+1")
        i += 1
    i += 1

x = "".join(a)
print(eval(x))
