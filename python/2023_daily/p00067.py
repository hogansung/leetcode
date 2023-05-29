class Solution:
    def addBinary(self, a: str, b: str) -> str:
        reverse_a_list = list(a)[::-1]
        reverse_b_list = list(b)[::-1]
        na, nb = len(reverse_a_list), len(reverse_b_list)
        carry = 0
        idx = 0
        reverse_sum_list = []
        while idx < max(na, nb) or carry:
            if idx < na:
                carry += 1 if reverse_a_list[idx] == "1" else 0
            if idx < nb:
                carry += 1 if reverse_b_list[idx] == "1" else 0
            reverse_sum_list.append("1" if carry % 2 else "0")
            carry //= 2
            idx += 1
        return "".join(reverse_sum_list[::-1])
