from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ns, np = len(s), len(p)
        char_count = [0 for _ in range(26)]
        for c in p:
            char_idx = ord(c) - ord("a")
            char_count[char_idx] += 1
        match_count = sum([1 if count == 0 else 0 for count in char_count])
        results = []
        for idx in range(ns):
            char_idx = ord(s[idx]) - ord("a")
            char_count[char_idx] -= 1
            if char_count[char_idx] == 0:
                match_count += 1
            elif char_count[char_idx] == -1:
                match_count -= 1
            if idx < np - 1:
                continue
            if match_count == 26:
                results.append(idx - (np - 1))
            char_idx = ord(s[idx - (np - 1)]) - ord("a")
            char_count[char_idx] += 1
            if char_count[char_idx] == 0:
                match_count += 1
            elif char_count[char_idx] == +1:
                match_count -= 1
        return results
