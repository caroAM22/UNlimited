n = int(input())
izq = list(map(int, input().split()))
der = list(map(int, input().split()))


def contar(l):
    e = set(l)
    j = 0
    c = 0
    while len(e):
        if l[j] in e:
            c += 1
            e.remove(l[j])
            j = l[j] - 1
        else:
            j = next(iter(e)) - 1
            c -= 1
    return c - 1


print(contar(der) + contar(izq))
