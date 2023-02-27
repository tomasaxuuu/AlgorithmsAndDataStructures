n, m = (int(s) for s in input().split())
g = [[0 for j in range(n)] for i in range(n)]


for i in range(m):
    a, b = (int(s) for s in input().split())
    a -= 1
    b -= 1
    g[a][b] = 1
    g[b][a] = 1

for i in range(n):
    for j in range(n):
        if g[i][j] == 1:
            for k in range(n):
                if k != j and k != i and g[i][k] + g[j][k] == 1:
                    print("NO")
                    exit()
print("YES")