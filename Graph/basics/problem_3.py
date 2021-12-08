v, r = map(int, input().split())
dp = [["0"]*v for j in range(v)]
for i in range(r):
    u, v = map(int, input().split())
    dp[v-1][u-1] = '1'
    dp[u-1][v-1] = '1'
for i in dp:
    print(''.join(i))