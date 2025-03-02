class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        temp = targetSum - root.val
        if not root.left and not root.right :
            if temp == 0:
                return True
            else:
                return False

        if self.hasPathSum(root.left, temp):
            return True
        if self.hasPathSum(root.right, temp):
            return True

        return False

