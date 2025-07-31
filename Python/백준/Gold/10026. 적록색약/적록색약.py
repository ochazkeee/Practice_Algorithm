import sys
from collections import deque

def quest(n,arr):

    division = [[True]*n for _ in range(n)]
    directions = [(0,1),(1,0),(0,-1),(-1,0)]
    cnt=0
    q = deque()

    for i in range(n):
        for j in range(n):
            if division[i][j]==True:
                cnt+=1
                q.append((i,j))
                while q:
                    y, x = q.popleft()
                    for direction in directions:
                        dy, dx = direction
                        ny, nx = y + dy, x + dx
                        if 0<=ny<n and 0<=nx<n:
                            if arr[y][x]==arr[ny][nx] and division[ny][nx]==True:
                                division[ny][nx]=False
                                q.append((ny,nx))
    return cnt

def blindness(n,arr):
    for i in range(n):
        for j in range(n):
            if arr[i][j]=='R':
                arr[i][j]='G'

    return arr




N = int(sys.stdin.readline())
arr = [list(sys.stdin.readline().strip()) for _ in range(N)]
print(quest(N,arr),end=" ")
b= blindness(N,arr)
print(quest(N,b))