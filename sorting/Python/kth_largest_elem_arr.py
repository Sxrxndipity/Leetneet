class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        k = len(nums) - k
        def quickSelect(l,r):
            pivot, left = nums[r], l
            for i in range(l,r):
                if nums[i] <= pivot:
                    nums[left],nums[i] = nums[i], nums[left]
                    left += 1
            nums[left], nums[r] = nums[r], nums[left]

            if left > k:
                return quickSelect(l, left-1)
            elif left < k:
                return quickSelect(left+1, r)
            else:
                return nums[left]

        return quickSelect(0, len(nums)-1)
