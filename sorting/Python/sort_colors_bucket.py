#sort in place
class Solution:
    def sortColors(self, nums: list[int]) -> None:
        counts = [0,0,0]
        for n in nums:
            counts[n] += 1
        c = 0
        for i in range(len(counts)):
            for j in range(counts[i]):
                nums[c] = i
                c+=1
