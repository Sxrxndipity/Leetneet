class Solution:
    def sortArray(self, nums: list[int]) -> list[int]:
        self.mergeSort(nums)
        return nums


    def mergeSort(self, arr):
        left_arr = arr[:len(arr)//2]
        right_arr = arr[len(arr)//2:]

        if len(arr) > 1:
            self.mergeSort(right_arr)
            self.mergeSort(left_arr)

            i = j = k = 0
            while k < len(arr):
                if i < len(left_arr) and (j >= len(right_arr) or left_arr[i] <= right_arr[j]):
                    arr[k] = left_arr[i]
                    i += 1
                else:
                    arr[k] = right_arr[j]
                    j += 1
                k += 1
"""
Longer version
            while i < len(left_arr) and j < len(right_arr):
                if left_arr[i] < right_arr[j]:
                    arr[k] = left_arr[i]
                    i += 1
                else:
                    arr[k] = right_arr[j]
                    j += 1
                k += 1

            # If there are any remaining elements in left_arr or right_arr, add them
            while i < len(left_arr):
                arr[k] = left_arr[i]
                i += 1
                k += 1

            while j < len(right_arr):
                arr[k] = right_arr[j]
                j += 1
                k += 1
"""
