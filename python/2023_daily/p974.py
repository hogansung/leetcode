from collections import defaultdict
from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        counter = defaultdict(int)
        cnt = 0
        sumv = 0
        counter[0] = 1  # critical to have this
        for num in nums:
            sumv += num
            cnt += counter[sumv % k]
            counter[sumv % k] += 1
        return cnt
