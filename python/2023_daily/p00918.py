from typing import List

INF = 1e5


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        if max(nums) < 0:
            return max(nums)
        n = len(nums)
        maxv = -INF
        minv = +INF
        max_sumv = 0
        min_sumv = 0
        sumv = 0
        for idx in range(n):
            max_sumv += nums[idx]
            min_sumv += nums[idx]
            sumv += nums[idx]
            maxv = max(maxv, max_sumv)
            minv = min(minv, min_sumv)
            if max_sumv < 0:
                max_sumv = 0
            if min_sumv > 0:
                min_sumv = 0
        return max(maxv, sumv - minv)
