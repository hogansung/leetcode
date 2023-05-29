class Solution:
    def tribonacci(self, n: int) -> int:
        results = [0 for _ in range(37 + 1)]
        results[1] = results[2] = 1
        for idx in range(3, n + 1):
            results[idx] = sum(results[idx - 3 : idx])
        return results[n]
