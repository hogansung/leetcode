from typing import Tuple, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def dfs(self, root: TreeNode) -> Tuple[int, int, int]:
        m_min = m_max = root.val
        m_result = None
        if root.left:
            l_min, l_max, l_result = self.dfs(root.left)
            m_min = min(m_min, l_min)
            if m_result is None:
                m_result = root.val - l_max
            else:
                m_result = min(m_result, root.val - l_max)
            if l_result is not None:
                m_result = min(m_result, l_result)
        if root.right:
            r_min, r_max, r_result = self.dfs(root.right)
            m_max = max(m_max, r_max)
            if m_result is None:
                m_result = r_min - root.val
            else:
                m_result = min(m_result, r_min - root.val)
            if r_result is not None:
                m_result = min(m_result, r_result)
        return m_min, m_max, m_result

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        _, _, result = self.dfs(root)
        return result if result is not None else 0
