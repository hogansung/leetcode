class Solution {
public:
    vector<int> dfs(int l, int r, vector<int>& nums, vector<char>& ops) {
        if (l > r) {
            return vector<int>(1, nums[l]);
        } else {
            vector<int> ret;
            for (int m = l; m <= r; m++) {
                vector<int> ret_l = dfs(l, m-1, nums, ops);
                vector<int> ret_r = dfs(m+1, r, nums, ops);
                for (auto val_l : ret_l) {
                    for (auto val_r : ret_r) {
                        if (ops[m] == '+') {
                            ret.push_back(val_l + val_r);
                        } else if (ops[m] == '-') {
                            ret.push_back(val_l - val_r);
                        } else if (ops[m] == '*') {
                            ret.push_back(val_l * val_r);
                        } else {
                            assert(false);
                        }
                    }
                }
            }
            return ret;
        }
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        
        string str = "";
        for (auto c : input) {
            if (c >= '0' and c <= '9') {
                str.push_back(c);
            } else {
                if (str.length() > 0) {
                    nums.push_back(strtol(str.c_str(), 0, 10));
                }
                str = "";
                ops.push_back(c);
            }
        }
        
        assert(str.length() > 0);
        nums.push_back(strtol(str.c_str(), 0, 10));
        
        assert(nums.size() - 1 == ops.size());
        vector<int> ret = dfs(0, ops.size() - 1, nums, ops);
        return ret;
    }
};
