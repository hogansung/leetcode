class Solution {
public:
    struct myCMP {
        bool operator()(const string& str_a, 
                        const string& str_b) {
            string str_ab = str_a + str_b;
            string str_ba = str_b + str_a;
            int len_ab = str_ab.length();
            for (int i = 0; i < len_ab; i++) {
                if (str_ab[i] != str_ba[i]) {
                    return str_ab[i] > str_ba[i];
                }
            }
            return 0;
        }  
    };
    
    string largestNumber(vector<int>& nums) {
        vector<string> vct;
        for (auto num : nums) {
            vct.emplace_back(to_string(num));
        }
        sort(vct.begin(), vct.end(), myCMP());
        
        string ret;
        for (auto v : vct) {
            ret += v;
        }
        
        reverse(ret.begin(), ret.end());
        while(ret.length() > 1 and ret.back() == '0') {
            ret.pop_back();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
