class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for (auto num : nums) {
            um[num] += 1;
        }
        
        int cnt = 0;
        if (k == 0) {
            for (auto p : um) {
                if (p.second >= 2) {
                    cnt += 1;
                }
            }
        } else if (k > 0) {
            for (auto p : um) {
                if (um.find(p.first + k) != um.end()) {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
