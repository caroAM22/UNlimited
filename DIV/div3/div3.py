dic = [
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
]

y = int(input())
for i in range(y):
    n = int(input())
    l = list(input())
    cont = {}
    pro = set()
    for j in range(len(l)):
        ind = dic.index(l[j]) + 1
        if l[j] in cont:
            c = cont[l[j]]
            cont[l[j]] = c + 1
        else:
            cont[l[j]] = 1
        if cont[l[j]] == ind:
            pro.add(l[j])
    print(len(pro))

print(7**8**10)
