N = int(input())
material=list(input().split())
Guess = list(input().split())

for i in range(N):
    if material[i] not in Guess:
        print(material[i])