import math


class Solution:
    def _countOdds(self, number: int) -> int:
        return math.ceil(number / 2)

    def countOdds(self, low: int, high: int) -> int:
        return self._countOdds(high) - self._countOdds(low - 1)
