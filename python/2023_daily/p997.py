from typing import List


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        in_degrees = [0 for _ in range(n)]
        out_degrees = [0 for _ in range(n)]
        for u, v in trust:
            u -= 1
            v -= 1
            in_degrees[v] += 1
            out_degrees[u] += 1
        for u in range(n):
            if out_degrees[u] == 0 and in_degrees[u] == n - 1:
                return u + 1
        return -1
