from collections import Counter


class Solution:
    def countStudents(self, students: list[int], sandwiches: list[int]) -> int:
        res = len(students)
        cnt = Counter(students)
        for s in sandwiches:
            if cnt[s] > 0:
                res -= 1
                cnt[s] -= 1
            else:
                return res
        return res
