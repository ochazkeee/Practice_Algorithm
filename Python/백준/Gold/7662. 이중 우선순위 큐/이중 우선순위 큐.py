import sys
import heapq

T = int(sys.stdin.readline())
for _ in range(T):
    k = int(sys.stdin.readline())
    min_heap = []
    max_heap = []
    entry_count = {}  # 각 값의 삽입 횟수를 추적

    for _ in range(k):
        command, value = sys.stdin.readline().split()
        value = int(value)

        if command == 'I':
            heapq.heappush(min_heap, value)
            heapq.heappush(max_heap, -value)
            if value in entry_count:
                entry_count[value] += 1
            else:
                entry_count[value] = 1
        elif command == 'D':
            if value == 1:  # 최댓값 삭제
                while max_heap and entry_count.get(-max_heap[0], 0) == 0:
                    heapq.heappop(max_heap)
                if max_heap:
                    max_value = -heapq.heappop(max_heap)
                    entry_count[max_value] -= 1
            elif value == -1:  # 최솟값 삭제
                while min_heap and entry_count.get(min_heap[0], 0) == 0:
                    heapq.heappop(min_heap)
                if min_heap:
                    min_value = heapq.heappop(min_heap)
                    entry_count[min_value] -= 1

    # 힙을 정리하여 남아있는 최댓값, 최솟값을 확인
    while min_heap and entry_count.get(min_heap[0], 0) == 0:
        heapq.heappop(min_heap)
    while max_heap and entry_count.get(-max_heap[0], 0) == 0:
        heapq.heappop(max_heap)

    if min_heap and max_heap:
        print(-max_heap[0], min_heap[0])
    else:
        print('EMPTY')
