class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # Check if all uppercase
        if all([char.isupper() for char in word]):
            return True

        # Check if all lowercase
        if all([char.islower() for char in word]):
            return True

        # Check if first char is uppercase and the rest chars are lowercase
        if word[0].isupper() and all([char.islower() for char in word[1:]]):
            return True

        return False
