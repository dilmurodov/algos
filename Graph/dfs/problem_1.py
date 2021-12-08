v, r = map(int, input().split())
dp = {j: [] for j in range(1, v+1)}
for i in range(r):
    u1, v1 = map(int, input().split())
    dp[u1].append(v1)
    dp[v1].append(u1)

used = []
def dfs(v):
    used.append(v)
    for j in dp[v]:
        if j not in used:
            dfs(j)
            used.append(v)
home = int(input())
dfs(home)
print(len(used))
print(*used)