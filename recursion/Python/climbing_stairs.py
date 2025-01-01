class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        return self.climbStairs(n-1)+self.climbStairs(n-2)
# alternatively (DP solution)
# one, two = 1, 1
# for i in range(n-1):
#     temp = one
#     one = one + two
#     two = temp
# return one
