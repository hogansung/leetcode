from typing import Tuple, List


class Solution:
    def dfs(self, u: int, p: int) -> Tuple[bool, int]:
        has_apple = self.hasApple[u]
        cost = 0
        for v in self.edges[u]:
            if v == p:
                continue
            s_has_apple, s_cost = self.dfs(v, u)
            if s_has_apple:
                has_apple = True
                cost += s_cost + 2
        return has_apple, cost

    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        self.n = n
        self.edges = [[] for _ in range(n)]
        for u, v in edges:
            self.edges[u].append(v)
            self.edges[v].append(u)
        self.hasApple = hasApple
        has_apple, cost = self.dfs(0, -1)
        return cost if has_apple else 0
