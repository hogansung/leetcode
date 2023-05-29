from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def _preorderTraversal(self, root: Optional[TreeNode]):
        self.container.append(root.val)
        if root.left is not None:
            self._preorderTraversal(root.left)
        if root.right is not None:
            self._preorderTraversal(root.right)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.container = []
        if root is not None:
            self._preorderTraversal(root)
        return self.container
