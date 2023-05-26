class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        one_counts = [0 for _ in range(n + 1)]
        for idx, c in enumerate(s):
            one_counts[idx + 1] = one_counts[idx] + 1 if c == "1" else one_counts[idx]
        minv = n
        for idx in range(n + 1):  # index >= idx are all ones
            minv = min(
                minv, one_counts[idx] + (n - idx) - (one_counts[n] - one_counts[idx])
            )
        return minv
