from typing import List


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        num_rows = len(strs)
        num_cols = len(strs[0])
        cnt = 0
        for jdx in range(num_cols):
            suc = True
            prev_char = strs[0][jdx]
            for idx in range(1, num_rows):
                if prev_char > strs[idx][jdx]:
                    suc = False
                prev_char = strs[idx][jdx]
            if not suc:
                cnt += 1
        return cnt
