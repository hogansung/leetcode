from typing import List


class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        word_set = set(words)
        results = []
        for word in words:
            n = len(word)
            states = [False for _ in range(n + 1)]
            states[0] = True
            for idx in range(n):
                if not states[idx]:
                    continue
                for jdx in range(idx + 1, n + 1):
                    if idx == 0 and jdx == n:  # exclude self
                        continue
                    if word[idx:jdx] in word_set:
                        states[jdx] = True
            if states[n] == True:
                results.append(word)
        return results
