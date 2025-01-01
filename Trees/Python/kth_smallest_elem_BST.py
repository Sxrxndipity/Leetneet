class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.counter = 1
        self.res = -1

        def inorder(root):
            if not root or self.res > 0:
                return
            inorder(root.left)
            if self.counter == k:
                self.res = root.val
            self.counter += 1
            inorder(root.right)

        inorder(root)
        return self.res

