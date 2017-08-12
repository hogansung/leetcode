class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> vct;
        if (n == 0) {
            return vct;
        } else {
            int st = nums[0];
            int ed = nums[0];
            for (int i = 1; i < n; i++) {
                if (ed + 1 == nums[i]) {
                    ed = nums[i];
                } else {
                    if (st == ed) {
                        vct.emplace_back(to_string(st));
                    } else {
                        vct.emplace_back(to_string(st) + "->" + to_string(ed));
                    }
                    st = ed = nums[i];
                }
            }
            
            if (st == ed) {
                vct.emplace_back(to_string(st));
            } else {
                vct.emplace_back(to_string(st) + "->" + to_string(ed));
            }
        }
        return vct;
    }
};
