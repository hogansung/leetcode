from typing import List


class Solution:
    def dfs(self, idx: int, bobNumArrows: int) -> int:
        if idx == 12:
            if bobNumArrows <= self.numArrows:
                return 0
            else:
                return -1

        # # If Bob wants to win `idx` round
        win_score = self.dfs(idx + 1, bobNumArrows + self.aliceArrows[idx] + 1)
        if win_score >= 0:
            win_score += idx
        # If Bob wants to give up `idx` round
        lose_score = self.dfs(idx + 1, bobNumArrows)

        if win_score > lose_score:
            self.rcd[idx][bobNumArrows] = bobNumArrows + self.aliceArrows[idx] + 1
            return win_score
        else:
            self.rcd[idx][bobNumArrows] = bobNumArrows
            return lose_score

    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        self.numArrows = numArrows
        self.aliceArrows = aliceArrows
        self.rcd = [dict() for _ in range(12)]
        result = self.dfs(0, 0)
        assert result > -1

        bobArrows = [0 for _ in range(12)]
        bobArrow = 0
        for idx in range(0, 12):
            nextBobArrow = self.rcd[idx][bobArrow]
            if nextBobArrow > bobArrow:
                bobArrows[idx] = aliceArrows[idx] + 1
            bobArrow = nextBobArrow
        bobArrows[-1] = sum(aliceArrows) - sum(bobArrows[:-1])
        return bobArrows
