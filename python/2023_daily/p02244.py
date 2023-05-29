import math
from collections import defaultdict
from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        count_by_value = defaultdict(int)
        for task in tasks:
            count_by_value[task] += 1
        cnt = 0
        for value, count in count_by_value.items():
            if count == 1:
                return -1
            else:
                cnt += math.ceil(count / 3)  # remaining 1 or 2 needs one more round
        return cnt
