from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        q = deque()

        if root:
            q.append(root)

        while len(q) > 0:
            level = len(q)

            for i in range(level):
                cur = q.popleft()

                if i == (level-1):
                    res.append(cur.val)

                if cur.left:
                    q.append(cur.left)

                if cur.right:
                    q.append(cur.right)

        return res
