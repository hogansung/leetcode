class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vct;
        for (auto num : nums) {
            int t = lower_bound(vct.begin(), vct.end(), num) - vct.begin();
            if (t == vct.size()) {
                vct.push_back(num);
            } else {
                vct[t] = num;
            }
        }
        return vct.size();
    }
};
