from typing import List


class Solution:
    def dfs(self, u):
        maxv = 0
        maxls = []
        for v in self.edges[u]:
            s_maxv, s_maxl = self.dfs(v)
            if self.s[v] != self.s[u]:
                maxls.append(s_maxl)
            maxv = max(maxv, s_maxv)
        sorted_maxls = sorted(maxls, reverse=True)
        maxv = max(maxv, sum(sorted_maxls[:2]) + 1)
        maxl = sum(sorted_maxls[:1]) + 1
        return maxv, maxl

    def longestPath(self, parent: List[int], s: str) -> int:
        self.n = len(parent)
        self.edges = [[] for _ in range(self.n)]
        for v, u in list(enumerate(parent))[1:]:
            self.edges[u].append(v)
        self.s = s
        maxv, _ = self.dfs(0)
        return maxv
