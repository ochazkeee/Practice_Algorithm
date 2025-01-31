N = int(input())
T = int(input())
stack = list(map(int,input().split()))
pos = -1
temp = list(map(int,input().split()))
for i in range(T):
    pos += temp[i]
    pos %= 2*N
    print(stack[pos],end=" ")
    pos -=1