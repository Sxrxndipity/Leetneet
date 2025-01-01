class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        self.quicksort(nums, 0, len(nums)-1)
        return nums

    def quicksort(self, arr, s, e):
        pivot = arr[e]
        left = s
        if not (e-s+1) > 1:
            return arr
        for i in range(s,e):
            if arr[i] < pivot:
                tmp = arr[left]
                arr[left] = arr[i]
                arr[i] = tmp
                left += 1
        arr[e] = arr[left]
        arr[left] = pivot

        self.quicksort(arr, s, left-1)
        self.quicksort(arr, left+1, e)

        return arr
