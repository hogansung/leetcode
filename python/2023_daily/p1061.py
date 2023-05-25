class Solution:
    def find_parent(self, char: str):
        if self.parent_by_char[char] == char:
            return char
        else:
            self.parent_by_char[char] = self.find_parent(self.parent_by_char[char])
            return self.parent_by_char[char]

    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        self.chars = [chr(ord("a") + idx) for idx in range(26)]
        self.parent_by_char = {char: char for char in self.chars}

        for _s1, _s2 in zip(s1, s2):
            parent_s1 = self.find_parent(_s1)
            parent_s2 = self.find_parent(_s2)
            if parent_s1 < parent_s2:
                self.parent_by_char[parent_s2] = parent_s1
            else:
                self.parent_by_char[parent_s1] = parent_s2

        return "".join(self.find_parent(char) for char in baseStr)
