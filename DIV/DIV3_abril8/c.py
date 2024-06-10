from collections import deque

for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    l = deque(map(int, input().split()))
    k1 = k // 2
    if k % 2 != 0:
        k1 += 1
    k2 = k - k1
    while len(l) > 1 and (k1 > 0 or k2 > 0):
        left = l.popleft()
        right = l.pop()
        rl = min(left, k1)
        rr = min(right, k2)
        left -= rl
        right -= rr
        if left != 0:
            l.appendleft(left)
            k1 = 0
        else:
            k1 -= rl
        if right != 0:
            l.append(right)
            k2 = 0
        else:
            k2 -= rr
    if len(l) == 1:
        k = k1 + k2
        right = l.pop()
        rr = min(right, k)
        right -= rr
        if right != 0:
            l.append(right)
    print(n - len(l))
