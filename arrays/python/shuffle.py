
def shuffle(nums: list[int], n:  int) -> int:
    arr = []
    x = 0
    y = n
    for i in range(len(nums)):
        if i % 2 == 0:
            arr.append(nums[x])
            x += 1
        else:
            arr.append(nums[y])
            y += 1
    return arr
