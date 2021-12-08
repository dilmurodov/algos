v = int(input())
dp = [["0"]*v for i in range(v)]

for i in range(v):
    nums = list(map(int, input().split()))
    for j in nums[1::]:
        dp[i][j-1] = "1"
for i in dp:
    print(''.join(i))