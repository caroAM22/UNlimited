a, b = list(map(int, input().split()))


def sequence(a, b):
    if a == b:
        return "1"
    st = set()
    ans = str(a)
    for i in range(98):
        l = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        for number in ans:
            l[int(number)] += 1
        ans = ""
        for j in range(10):
            if l[j] > 0:
                ans += str(l[j]) + str(j)
        # print(ans)
        if ans == str(b):
            return i + 2
        if ans not in st:
            st.add(ans)
        else:
            return "Does not appear"
    return "I’m bored"


print(sequence(a, b))
