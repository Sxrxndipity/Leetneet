class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        res = nums.copy()
        for i in range(len(nums)):
            j = i-1
            if j <= 0 and res[j] > res[j+1]:
                temp = res[j]
                res[j] = res[j+1]
                res[j+1] = temp
                j -= 1
        return res
