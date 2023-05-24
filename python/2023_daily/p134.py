from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        diffs = [_gas - _cost for _gas, _cost in zip(gas, cost)]
        n = len(diffs)

        start_idx = -1
        acc_sum = 0
        for idx in range(2 * n):
            if start_idx >= 0 and idx - start_idx == n:
                return start_idx
            acc_sum += diffs[idx % n]
            if acc_sum < 0:
                start_idx = -1
                acc_sum = 0
            elif start_idx == -1:
                start_idx = idx
        return -1
