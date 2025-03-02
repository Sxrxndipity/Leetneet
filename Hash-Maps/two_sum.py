class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j and i < j:
                    sum = nums[i] + nums[j]
                    map[sum] = [i,j]
        return map[target]

class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}
        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i
