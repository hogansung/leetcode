class Solution {
public:
    char to_upper(char c) {
        if (c >= 'a' and c <= 'z') {
            return c - 'a' + 'A';
        } else {
            return c;
        }
    }
    
    string licenseKeyFormatting(string S, int K) {
        string nS;
        for (auto c : S) {
            if (c != '-') {
                nS.push_back(c);
            }
        }
        
        int len = nS.length();
        string nnS;
        for (int i = 0; i < len%K; i++) {
            nnS.push_back(to_upper(nS[i]));
        }
        for (int i = len%K; i < len; i+=K) {
            if (i > 0) {
                nnS.push_back('-');
            }
            for (int j = 0; j < K; j++) {
                nnS.push_back(to_upper(nS[i+j]));
            }
        }
        return nnS;
    }
};
