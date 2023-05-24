class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<long long> nnums;
        nnums.push_back((long long)lower-1);
        for (auto num : nums) {
            nnums.push_back(num);
        }
        nnums.push_back((long long)upper+1);
        
        int n = nnums.size();
        vector<string> ret;
        for (int i = 0; i < n-1; i++) {
            if (nnums[i+1] - nnums[i] == 0 or
                nnums[i+1] - nnums[i] == 1) {
                // do nothing
            } else if (nnums[i+1] - nnums[i] == 2) {
                ret.emplace_back(to_string(nnums[i]+1));
            } else {
                string str;
                str += to_string(nnums[i]+1);
                str += "->";
                str += to_string(nnums[i+1]-1);
                ret.emplace_back(str);
            }
        }
        return ret;
    }
};
