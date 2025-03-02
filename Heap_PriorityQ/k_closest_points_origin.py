import math
import heapq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        dst = {i: math.sqrt(points[i][0]**2 + points[i][1]**2) for i in range(len(points))}
        heap = []

        for key,v in dst.items():
            heapq.heappush(heap, (v,key))

        for i in range(k):
            p = heapq.heappop(heap)
            x = p[1]
            res.append(points[x])

        return res

class Solution2:
    def kClosest(self, points, k):
        res = []
        minHeap = []
        for x, y  in points:
            dist = (x**2) + (y**2)
            minHeap.append([dist, x, y])

        heapq.heapify(minHeap)

        while k > 0:
            dist, x, y = heapq.heappop(minHeap)
            res.append([x,y])
            k -=1

        return res

