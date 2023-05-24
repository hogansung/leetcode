class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        chars = list(pattern)
        words = s.split()
        if len(chars) != len(words):
            return False

        word_to_char_dict = dict()
        char_to_word_dict = dict()
        for char, word in zip(chars, words):
            if word in word_to_char_dict and word_to_char_dict[word] != char:
                return False
            word_to_char_dict[word] = char
            if char in char_to_word_dict and char_to_word_dict[char] != word:
                return False
            char_to_word_dict[char] = word
        return True
