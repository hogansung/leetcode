class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        } else {
            int len = s.length();
            int rnd = 2 * numRows - 2;
            
            string ret;
            { // first row
                for (int i = 0; i < len; i+=rnd) {
                    ret.push_back(s[i]);
                }
            }
            { // middle rows
                for (int j = 1; j < numRows-1; j++) {
                    for (int i = 0; i+j < len or i+rnd-j < len; i+=rnd) {
                        if (i+j < len) {
                            ret.push_back(s[i+j]);
                        }
                        if (i+rnd-j < len) {
                            ret.push_back(s[i+rnd-j]);
                        }
                    }
                }
            }
            { // last row
                for (int i = 0; i+numRows-1 < len; i+=rnd) {
                    ret.push_back(s[i+numRows-1]);
                }
            }
            return ret;
        }
    }
};
