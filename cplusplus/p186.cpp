class Solution {
public:
    void split(vector<string>& vct, string& s) {
        stringstream ss(s);
        string str;
        while (getline(ss, str, ' ')) {
            if (str.length() > 0) {
                vct.emplace_back(str);
            }
        }
    }
    
    void reverseWords(string &s) {
        vector<string> vct;
        split(vct, s);
        
        int n = vct.size();
        reverse(vct.begin(), vct.end());
        
        string ret;
        if (n == 0) {
            s = ret;
        } else {
            ret += vct[0];
            for (int i = 1; i < n; i++) {
                ret += " ";
                ret += vct[i];
            }
            s = ret;
        }
    }
};
