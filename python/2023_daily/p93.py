class Solution:
    def check_digits(self) -> bool:
        for digits in self.digits_list:
            if len(digits) == 0:
                return False
            if len(digits) >= 2 and digits[0] == "0":
                return False
            if int("".join(digits)) > 255:
                return False
        return True

    def _restoreIpAddresses(self, idx: int, jdx: int) -> None:
        if idx == self.n and jdx == 3:
            if self.check_digits():
                self.results.append(
                    ".".join(["".join(digits) for digits in self.digits_list])
                )
        else:
            # Option A: Append the digit to current jdx and move forward
            if idx < self.n:
                self.digits_list[jdx].append(self.s[idx])
                self._restoreIpAddresses(idx + 1, jdx)
                self.digits_list[jdx].pop()
            # Option B: Move to next jdx
            if jdx < 3:
                self._restoreIpAddresses(idx, jdx + 1)

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.s = s
        self.n = len(s)
        self.digits_list = [[] for _ in range(4)]
        self.results = []
        self._restoreIpAddresses(0, 0)
        return self.results
