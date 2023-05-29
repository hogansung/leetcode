from typing import List


class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        results = []
        for idx in range(n):
            results.append(nums[idx])
            results.append(nums[n + idx])
        return results
