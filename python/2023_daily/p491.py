from typing import List


class Solution:
    def _findSubsequences(self, idx: int):
        if idx == self.n:
            if len(self.result) >= 2:
                self.results.append(self.result.copy())
        else:
            if len(self.result) == 0 or self.result[-1] <= self.nums[idx]:
                self.result.append(self.nums[idx])
                self._findSubsequences(idx + 1)
                self.result.pop()
            self._findSubsequences(idx + 1)

    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        self.n = len(nums)
        self.nums = nums
        self.result = []
        self.results = []
        self._findSubsequences(0)
        return list(map(list, set(map(tuple, self.results))))
