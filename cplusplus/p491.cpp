struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    void dfs(int t, const int n, vector<int>& nums, 
             vector<int>& vct, unordered_set<vector<int>, VectorHash>& us) {
        if (t == n) {
            if (vct.size() >= 2) {
                us.emplace(vct);
            }
        } else {
            dfs(t+1, n, nums, vct, us);
            if (vct.size() == 0 or vct.back() <= nums[t]) {
                vct.push_back(nums[t]);
                dfs(t+1, n, nums, vct, us);
                vct.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> us;
        vector<int> vct;
        dfs(0, nums.size(), nums, vct, us);
        
        vector<vector<int>> ret;
        for (vector<int> lst : us) {
            ret.push_back(lst);
        }
        return ret;
    }
};
