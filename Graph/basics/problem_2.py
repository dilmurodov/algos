# 1-method

v, r = map(int, input().split())
dp = [[] for i in range(v)]

for i in range(r):
    u, v = map(int, input().split())
    dp[u-1].append(v)
    dp[v-1].append(u)

for i in dp:
    i.sort()
    i.insert(0, len(i))
for i in dp:
    print(*i)
