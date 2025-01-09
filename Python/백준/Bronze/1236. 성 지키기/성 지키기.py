n,m = map(int,input().split())

Matrix = []
for i in range(n):
    Matrix.append(list(input().strip()))

guard = 0
for i in range(n):
    if 'X' not in Matrix[i]:
        key=1
        for j in range(m):
            column = [row[j] for row in Matrix]
            if 'X' not in column:
                Matrix[i][j] = 'X'
                guard += 1
                key=0
                break
        if key==1:
            Matrix[i][0]='X'
            guard += 1






for i in range(m):
    column = [row[i] for row in Matrix]
    if 'X' not in column:
        guard += 1


print(guard)

