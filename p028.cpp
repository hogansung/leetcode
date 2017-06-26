class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_h = haystack.length();
        int len_n = needle.length();
        
        for (int i = 0; i <= len_h-len_n; i++) {
            bool suc = true;
            for (int j = 0; j < len_n; j++) {
                if (haystack[i+j] != needle[j]) {
                    suc = false;
                }
            }
            if (suc == true) {
                return i;
            }
        }
        return -1;
    }
};
