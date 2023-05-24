class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
        for (char c : s) {
            if (c >= 'a' and c <= 'z') {
                ns.push_back(c);
            } else if (c >= 'A' and c <= 'Z') {
                ns.push_back(c-'A'+'a');
            } else if (c >= '0' and c <= '9') {
                ns.push_back(c);
            }
        }
        
        int len = ns.length();
        bool suc = true;
        for (int i = 0; i < len/2; i++) {
            if (ns[i] != ns[len-1-i]) {
                suc = false;
            }
        }
        return suc;
    }
};
