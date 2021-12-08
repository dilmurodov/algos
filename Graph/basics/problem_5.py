v = int(input())
def mygenerator():
    for i in range(v):
        a = input()
        for index, j in enumerate(a[i::]):
            if j == "1":
                if i < index+i+1:
                    yield i+1, index+i+1
                else:
                    yield index+i+1, i+1

generator = mygenerator()

a = [i for i in generator]

print(len(a))

for i in a:
    print(*i)