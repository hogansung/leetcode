class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        char_lists = [[] for _ in range(numRows)]
        for idx, c in enumerate(s):
            converted_idx = idx % (2 * (numRows - 1))
            if converted_idx < numRows:
                char_lists[converted_idx].append(c)
            else:
                char_lists[2 * (numRows - 1) - converted_idx].append(c)
        return "".join(["".join(char_list) for char_list in char_lists])
