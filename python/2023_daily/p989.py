from typing import List


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        reverse_num = num[::-1]
        reverse_k_list = list(map(int, list(str(k))[::-1]))
        reverse_result = []
        carry = 0
        idx = 0
        while idx < max(len(reverse_num), len(reverse_k_list)) or carry:
            if idx < len(reverse_num):
                carry += reverse_num[idx]
            if idx < len(reverse_k_list):
                carry += reverse_k_list[idx]
            reverse_result.append(carry % 10)
            carry //= 10
            idx += 1
        return reverse_result[::-1]
