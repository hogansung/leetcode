from collections import defaultdict


class Solution:
    def minimizedStringLength(self, s: str) -> int:
        count_by_char = defaultdict(int)
        for c in s:
            count_by_char[c] += 1
        result = 0
        for c, count in count_by_char.items():
            result += min(count, 1)
        return result
