#approach: decision tree two choices left branch includes a candidate right one excludes it
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        def dfs(i, comb, sum):
            if sum == target:
                res.append(comb.copy())     #make a copy because comb is changing
                return
            if i >= len(candidates) or sum > target:
                return

            #including a candidate
            comb.append(candidates[i])
            dfs(i, comb, sum + candidates[i])

            #eliminating a candidate
            comb.pop()
            dfs(i+1, comb, sum)

        dfs(0, [], 0)

        return res
