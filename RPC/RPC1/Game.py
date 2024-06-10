x1, y1 = list(map(int, input().split()))
x2, y2 = list(map(int, input().split()))
x3, y3 = list(map(int, input().split()))
x4, y4 = list(map(int, input().split()))

d1 = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
d2 = ((x3 - x2) ** 2 + (y3 - y2) ** 2) ** 0.5
d3 = ((x4 - x3) ** 2 + (y4 - y3) ** 2) ** 0.5
d4 = ((x1 - x4) ** 2 + (y1 - y4) ** 2) ** 0.5

s = set([d1, d2, d3, d4])


def pendiente(x1, y1, x2, y2):
    if x1 == x2:
        return "vertical"
    else:
        return (y2 - y1) / (x2 - x1)


m1 = pendiente(x1, y1, x2, y2)
m2 = pendiente(x2, y2, x3, y3)
m3 = pendiente(x3, y3, x4, y4)
m4 = pendiente(x4, y4, x1, y1)

m = set([m1, m2, m3, m4])


if len(s) == 1:
    if "vertical" in m:
        if len(m) == 2 and 0.0 in m:
            print("square")
        else:
            print("rhombus")
    elif "vertical" not in m and 0.0 not in m and len(m) == 2:
        if m1 == -1 / m2:
            print("square")
        else:
            print("rhombus")
    else:
        print("rhombus")

elif len(m) == 2:
    if 0.0 in m and "vertical" in m:
        print("rectangle")
    elif 0.0 in m and "vertical" not in m:
        print("parallelogram")
    elif "vertical" in m and 0.0 not in m:
        print("parallelogram")
    else:
        if m1 == -1 / m2:
            print("rectangle")
        else:
            print("parallelogram")
elif len(m) == 3:
    print("trapezium")
else:
    if d1 == d2 and d3 == d4 or d2 == d3 and d1 == d4:
        print("kite")
    else:
        print("none")
