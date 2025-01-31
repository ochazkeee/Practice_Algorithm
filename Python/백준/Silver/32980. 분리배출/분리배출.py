N = int(input())
trash = []
result = 0
for i in range(N):
    trash.append(input())

cost = list(map(int, input().split()))
O_cost = int(input())
spe = ["P","C","V","S","G","F"]
cnt = [0,0,0,0,0,0]
for i in range(N):
    # 초기화
    for j in range(6):
        cnt[j]=0
    # 분리수거 항목 별로 추가
    for j in range(6):
        if spe[j] in trash[i]:
            cnt[j] += 1

    temp = 0
    pre = trash[i][0]
    for j in range(1,len(trash[i])):
        if trash[i][j] != pre:
            temp = 1
            break

    if temp == 1:
        result += len(trash[i]) * O_cost
    else:
        key =0
        for j in range(6):
            if cnt[j] !=0:
                if cost[j]>=O_cost:
                    result += len(trash[i]) * O_cost
                    key=1
                    break
                else:
                    result += len(trash[i]) * cost[j]
                    key=1
                    break
        if key==0:
            result += len(trash[i]) * O_cost

print(result)




