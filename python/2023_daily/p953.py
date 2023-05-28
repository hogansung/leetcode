from typing import List


class Solution:
    def check(self, word_a: str, word_b: str) -> bool:
        for char_a, char_b in zip(word_a, word_b):
            if self.order_idx_by_char[char_a] < self.order_idx_by_char[char_b]:
                return True
            if self.order_idx_by_char[char_a] > self.order_idx_by_char[char_b]:
                return False
        return len(word_a) <= len(word_b)

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        self.order_idx_by_char = dict(
            [(char, order_idx) for order_idx, char in enumerate(order)]
        )
        suc = True
        for idx in range(len(words) - 1):
            suc &= self.check(words[idx], words[idx + 1])
        return suc
