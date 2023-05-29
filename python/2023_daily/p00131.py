from typing import List


class Solution:
    def dfs(self, idx: int) -> None:
        if idx == self.n:
            self.results.append(self.result.copy())
        else:
            for n_idx in range(idx + 1, self.n + 1):
                split_idx = idx + n_idx - 1
                span = (n_idx - idx) // 2
                if span <= self.max_span_by_split_idx[split_idx]:
                    self.result.append(self.s[idx:n_idx])
                    self.dfs(n_idx)
                    self.result.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.s = s
        self.n = len(s)
        self.max_span_by_split_idx = [0 for _ in range(2 * self.n - 1)]
        for split_idx in range(2 * self.n - 1):
            if split_idx % 2 == 0:
                for span in range(min(split_idx // 2, self.n - 1 - split_idx // 2) + 1):
                    if self.s[split_idx // 2 - span] == self.s[split_idx // 2 + span]:
                        self.max_span_by_split_idx[split_idx] = span
                    else:
                        break
            else:
                for span in range(
                    min(split_idx // 2, self.n - 1 - split_idx // 2 - 1) + 1
                ):
                    if (
                        self.s[split_idx // 2 - span]
                        == self.s[split_idx // 2 + 1 + span]
                    ):
                        self.max_span_by_split_idx[split_idx] = span + 1
                    else:
                        break
        self.result = []
        self.results = []
        self.dfs(0)
        return self.results
