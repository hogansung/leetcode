class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        char_cnt = [0 for _ in range(26)]
        for c in s1:
            char_idx = ord(c) - ord("a")
            char_cnt[char_idx] += 1
        match_cnt = sum(1 if cnt == 0 else 0 for cnt in char_cnt)
        for idx in range(len(s1) - 1):
            # Update char_cnt and match_cnt
            char_idx = ord(s2[idx]) - ord("a")
            char_cnt[char_idx] -= 1
            if char_cnt[char_idx] == 0:
                match_cnt += 1
            elif char_cnt[char_idx] == -1:
                match_cnt -= 1
        for idx in range(len(s1) - 1, len(s2)):
            # Update char_cnt and match_cnt
            char_idx = ord(s2[idx]) - ord("a")
            char_cnt[char_idx] -= 1
            if char_cnt[char_idx] == 0:
                match_cnt += 1
            elif char_cnt[char_idx] == -1:
                match_cnt -= 1
            # Check if successful
            if match_cnt == 26:
                return True
            # Update char_cnt and match_cnt
            char_idx = ord(s2[idx - (len(s1) - 1)]) - ord("a")
            char_cnt[char_idx] += 1
            if char_cnt[char_idx] == 0:
                match_cnt += 1
            elif char_cnt[char_idx] == 1:
                match_cnt -= 1
        return False
