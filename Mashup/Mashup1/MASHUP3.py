from math import gcd

n = int(input())
s = 0

for i in range(2, n):
    b = n
    while True:
        s += b % i
        if b // i == 0:
            break
        else:
            b //= i

mcd = gcd(s, n - 2)
sn = s // mcd
sd = (n - 2) // mcd

# Imprimir la fracción simplificada
print(f"{sn}/{sd}")
