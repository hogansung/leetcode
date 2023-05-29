from typing import List


class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        result = [[grid[idx][jdx] for jdx in range(m)] for idx in range(n)]
        for idx in range(n):
            for jdx in range(m):
                tl_set = set(
                    [grid[idx - 1 - kdx][jdx - 1 - kdx] for kdx in range(min(idx, jdx))]
                )
                br_set = set(
                    [
                        grid[idx + 1 + kdx][jdx + 1 + kdx]
                        for kdx in range(min(n - 1 - idx, m - 1 - jdx))
                    ]
                )
                result[idx][jdx] = abs(len(tl_set) - len(br_set))
        return result
