import bisect

n, p = list(map(int, input().split()))
prices = list(map(int, input().split()))

prices.sort()

i = bisect.bisect_left(prices, p)
if i >= len(prices):
    print(prices[-1])
elif prices[i] == p:
    print(p)
else:
    print(prices[i - 1])
