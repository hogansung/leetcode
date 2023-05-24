from typing import List


class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        sorted_costs = sorted(costs)
        idx = 0
        while idx < len(sorted_costs) and coins >= sorted_costs[idx]:
            coins -= sorted_costs[idx]
            idx += 1
        return idx
