import heapq

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [0] * len(stones)
        for i in range(len(stones)):
            heap[i] = -stones[i]
        heapq.heapify(heap)

        while len(heap) > 1:
            x = heapq.heappop(heap)
            y = heapq.heappop(heap)
            if x!=y:
                y = -(y-x)
                heapq.heappush(heap, y)
        if len(heap) == 1:
           return -heap[0]
        else:
            return 0
