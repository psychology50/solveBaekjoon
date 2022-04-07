import sys
input = sys.stdin.readline

class Heap:
    def __init__(self):
        self.data = []
    
    def heappush(self, value):
        self.data.append(value)
        current_index = len(self.data) - 1
        while current_index >= 0:
            if current_index % 2 == 0:
                parent_index = (current_index // 2) - 1
            else:
                parent_index = (current_index // 2)
            if parent_index >= 0 and self.data[parent_index] > self.data[current_index]:
                self.data[current_index], self.data[parent_index] = self.data[parent_index], self.data[current_index]
                current_index = parent_index
            else:
                break
    
    def heappop(self):
        if len(self.data) < 1:
            return 0
        self.data[0], self.data[-1] = self.data[-1], self.data[0]
        deleted_value = self.data.pop()
        self.re_sort(0)
        return deleted_value

    def re_sort(self, idx):
        current = idx
        left = idx * 2 + 1
        right = idx * 2 + 2

        if left <= len(self.data) - 1 and self.data[idx] > self.data[left]:
            current = left
            if right <= len(self.data) -1 and self.data[left] > self.data[right]:
                current = right
        elif right <= len(self.data) - 1 and self.data[idx] > self.data[right]:
            current = right

        if not current == idx:
            self.data[idx], self.data[current] = self.data[current], self.data[idx]
            self.re_sort(current)

def solution():
    n = int(input())
    heap = Heap()
    for _ in range(n):
        x = int(input())
        if x == 0:
            print(heap.heappop())
        else:
            heap.heappush(x)

solution()