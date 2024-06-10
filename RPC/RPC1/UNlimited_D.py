dna = input()

prefix_t = [0]
prefix_a = [0]
prefix_c = [0]
prefix_g = [0]

for i in range(1, len(dna) + 1):
    if dna[i - 1] == "T":
        prefix_t.append(prefix_t[i - 1] + 1)
        prefix_a.append(prefix_a[i - 1])
        prefix_c.append(prefix_c[i - 1])
        prefix_g.append(prefix_g[i - 1])
    if dna[i - 1] == "A":
        prefix_a.append(prefix_a[i - 1] + 1)
        prefix_t.append(prefix_t[i - 1])
        prefix_c.append(prefix_c[i - 1])
        prefix_g.append(prefix_g[i - 1])
    if dna[i - 1] == "C":
        prefix_c.append(prefix_c[i - 1] + 1)
        prefix_a.append(prefix_a[i - 1])
        prefix_t.append(prefix_t[i - 1])
        prefix_g.append(prefix_g[i - 1])
    if dna[i - 1] == "G":
        prefix_g.append(prefix_g[i - 1] + 1)
        prefix_a.append(prefix_a[i - 1])
        prefix_c.append(prefix_c[i - 1])
        prefix_t.append(prefix_t[i - 1])

m = int(input())

for i in range(m):
    l, r = list(map(int, input().split()))
    ans = {"A": 0, "C": 0, "G": 0, "T": 0}

    ans["A"] = prefix_a[r] - prefix_a[l - 1]
    ans["C"] = prefix_c[r] - prefix_c[l - 1]
    ans["G"] = prefix_g[r] - prefix_g[l - 1]
    ans["T"] = prefix_t[r] - prefix_t[l - 1]

    ans = {
        key: value
        for key, value in sorted(
            ans.items(),
            key=lambda x: (x[1], x[0] == "A", x[0] == "T", x[0] == "G", x[0] == "C"),
            reverse=True,
        )
    }
    print("".join(list(ans.keys())))
