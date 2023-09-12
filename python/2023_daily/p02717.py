from typing import List


class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        b_idx, e_idx = None, None
        for idx, num in enumerate(nums):
            if num == 1:
                b_idx = idx
            elif num == n:
                e_idx = idx
        if e_idx < b_idx:
            return b_idx + n - 1 - e_idx - 1
        else:
            return b_idx + n - 1 - e_idx
