from collections import defaultdict
from typing import List


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        maxv = 0
        l, r = 0, 0
        counter = defaultdict(int)
        while r < len(fruits):
            r_fruit = fruits[r]
            while len(counter) == 2 and r_fruit not in counter:
                l_fruit = fruits[l]
                counter[l_fruit] -= 1
                l += 1
                if counter[l_fruit] == 0:
                    del counter[l_fruit]
                    break
            counter[r_fruit] += 1
            r += 1
            maxv = max(maxv, r - l)
        return maxv
