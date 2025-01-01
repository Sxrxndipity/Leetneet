class Solution:
    def search(self, nums: list[int], target: int) -> int:
        low,high = 0, len(nums) - 1
        while (low <= high):
            m = (low + high) // 2
            if target < nums[m]:
                high = m - 1
            elif target > nums[m]:
                low = m + 1
            else:
                return m
        return -1
