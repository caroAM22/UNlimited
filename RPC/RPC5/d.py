n, m = list(map(int, input().split()))
lista = input()
r = str(eval(lista))
lista = list(lista.split())
lista.append("fin")
copia = []
b = False
acum = 1
keep = "error"


def paridad(r):
    if int(r[-1]) % 2 == 0:
        return "even"
    else:
        return "odd"


for i in range(0, len(lista), 2):
    if lista[i + 1] == "*" and b == False:
        b = True
        acum = acum * int(lista[i])
        keep = (i + 1) // 2
        copia.append(str(keep))
    elif lista[i + 1] == "*" and b == True:
        acum = acum * int(lista[i])
        copia.append(str(keep))
    elif lista[i + 1] != "*" and b == True:
        b = False
        acum = acum * int(lista[i])
        copia.append(str(keep))
        copia[keep] = acum
        keep = "error"
        acum = 1
    elif lista[i + 1] != "*" and b == False:
        copia.append(paridad(lista[i]))


def cambiaparidad(result):
    if result == "even":
        return "odd"
    else:
        return "even"


def buscar(i):
    return 2 * i - 2


def imprime(result):
    print(result)


result = paridad(r)
imprime(result)


for i in range(m):
    x, y = list(map(int, input().split()))
    x = x - 1
    if copia[x] == "odd" and paridad(str(y)) == "even":

        result = cambiaparidad(result)
        copia[x] = "even"
        imprime(result)
    elif copia[x] == "even" and paridad(str(y)) == "odd":

        result = cambiaparidad(result)
        copia[x] = "odd"
        imprime(result)
    elif isinstance(copia[x], int):

        p = paridad(str(copia[x]))
        copia[x] = copia[x] * y // int(lista[buscar(x + 1)])
        lista[buscar(x + 1)] = str(y)
        if paridad(str(copia[x])) != p:
            result = cambiaparidad(result)
            imprime(result)
        else:
            imprime(result)
    elif copia[x] != "odd" and copia[x] != "even" and isinstance(copia[x], str):
        j = int(copia[x])
        p = paridad(str(copia[j]))
        copia[j] = copia[j] * y // int(lista[buscar(x + 1)])
        lista[buscar(x + 1)] = str(y)
        if paridad(str(copia[j])) != p:
            result = cambiaparidad(result)
            imprime(result)
        else:
            imprime(result)
    else:
        imprime(result)
