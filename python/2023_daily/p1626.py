from typing import List


class Solution:
    def dp(self, idx: int, limit: int) -> int:
        if idx == self.n:
            return 0
        if self.states[idx][limit]:
            return self.states[idx][limit]
        self.states[idx][limit] = self.dp(idx + 1, limit)
        if self.ages[idx] >= limit:
            self.states[idx][limit] = max(
                self.states[idx][limit],
                self.dp(idx + 1, self.ages[idx]) + self.scores[idx],
            )
        return self.states[idx][limit]

    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        self.n = len(scores)
        sorted_score_age_pairs = sorted(zip(scores, ages))
        self.scores, self.ages = zip(*sorted_score_age_pairs)
        self.states = [[0 for _ in range(1000 + 1)] for _ in range(self.n + 1)]
        return self.dp(0, 0)
