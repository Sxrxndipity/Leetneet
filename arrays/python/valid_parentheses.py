class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        combo = {')': '(', '}': '{', ']': '['}
        for c in s:
            if c in combo:
                if stack and stack[-1] == combo[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if not stack else False
