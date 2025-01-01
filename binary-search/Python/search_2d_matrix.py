class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        f = []
        for row in matrix:
            for elem in row:
                f.append(elem)
        low, high = 0, len(f) - 1
        while (low <= high):
            m = (low + high) // 2
            if target < f[m]:
                high = m - 1
            elif target > f[m]:
                low = m + 1
            else:
                return True
        return False

