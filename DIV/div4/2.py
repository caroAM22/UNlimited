for _ in range(int(input())):
    x = {"A": 0, "B": 0, "C": 0}
    for i in range(3):
        l1 = list(input())
        for j in range(3):
            if l1[j] != "?":
                x[l1[j]] += 1
    if x["A"] != 3:
        print("A")
    elif x["B"] != 3:
        print("B")
    else:
        print("C")
