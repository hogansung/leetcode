class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        result = ""
        n1, n2 = len(str1), len(str2)
        for idx in range(min(n1, n2)):
            if str1[idx] != str2[idx]:
                return result
            n = idx + 1
            if n1 % n or n2 % n:
                continue
            suc = True
            candidate_str = str1[:n]
            for jdx in range(0, n1, n):
                if str1[jdx : n + jdx] != candidate_str:
                    suc = False
            for jdx in range(0, n2, n):
                if str2[jdx : n + jdx] != candidate_str:
                    suc = False
            if suc:
                result = candidate_str
        return result
