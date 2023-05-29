from typing import List


class Solution:
    def dfs(self, u: int, p: int) -> List[int]:
        counts = [0 for _ in range(26)]
        for v in self.edges[u]:
            if v == p:
                continue
            for idx, count in enumerate(self.dfs(v, u)):
                counts[idx] += count
        count_idx = ord(self.labels[u]) - ord("a")
        counts[count_idx] += 1
        self.ans[u] = counts[count_idx]
        return counts

    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        self.n = n
        self.edges = [[] for _ in range(n)]
        for u, v in edges:
            self.edges[u].append(v)
            self.edges[v].append(u)
        self.labels = labels
        self.ans = [int() for _ in range(n)]
        _ = self.dfs(0, -1)
        return self.ans
