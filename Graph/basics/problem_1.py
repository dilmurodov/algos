# 1-method

n = int(input())
a= []
for i in range(n):
    a.append(list(map(int, input())))
ans = [[] for i in range(n)]
for index, i in enumerate(a):
    for key, v in enumerate(i):
        if v == 1:
            ans[index].append(key+1)

for index, i in enumerate(ans):
    ans[index].insert(0, len(i))

for i in ans:
    for j in i:
        print(j, end=' ')
    print()

# 2-method

for _ in range(int(input())):
    r = input()
    print(r.count('1'), *[i+1 for i in range(len(r)) if r[i] == '1'])
