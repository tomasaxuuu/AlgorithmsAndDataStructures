n = int(input())

language = []

for _ in range(n):
    k = int(input())
    buff = set()
    for _ in range(k):
        buff.add(input())
    language.append(buff)

unic = set.union(*language)
intersec = set.intersection(*language)

print(len(intersec), '\n'.join(sorted(intersec)), len(unic), '\n'.join(sorted(unic)), sep='\n')