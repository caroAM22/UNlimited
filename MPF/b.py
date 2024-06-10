dict = {"1": 0, "2": 0}
for _ in range(int(input())):
    l = input().split()
    dict[l[1]] += int(l[2][1])
print(f"{dict['1']} x {dict['2']}")
