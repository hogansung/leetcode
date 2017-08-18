class Solution {
public:
    int calHash(const int n, vector<bool>& used) {
        int hash = 0;
        for (int i = 0; i < n; i++) {
            hash <<= 1;
            hash += used[i];
        }
        return hash;
    }
    
    bool dp(int t, const int n, int v, const int k,
            vector<int>& nums, vector<bool>& used, 
            vector<vector<bool>>& vis, vector<vector<bool>>& rcd) {
        int hash = calHash(n, used);
        if (t == 4) {
            return true;
        } else if (vis[t][hash] == true) {
            return rcd[t][hash];
        } else {
            bool suc = false;
            for (int i = 0; i < n; i++) {
                if (used[i] == false) {
                    if (v + nums[i] < k) {
                        used[i] = true;
                        suc |= dp(t, n, v+nums[i], k, nums, used, vis, rcd);
                        used[i] = false;
                    } else if (v + nums[i] == k) {
                        used[i] = true;
                        suc |= dp(t+1, n, 0, k, nums, used, vis, rcd);
                        used[i] = false;
                    }
                }
            }
            vis[t][hash] = true;
            return rcd[t][hash] = suc;
        }
    }
    
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        
        if (sum % 4 != 0) {
            return false;
        } else {
            int n = nums.size();
            vector<vector<bool>> vis(4, vector<bool>(1 << n, false));
            vector<vector<bool>> rcd(4, vector<bool>(1 << n, false));
            vector<bool> used(n, false);
            return dp(0, n, 0, sum / 4, nums, used, vis, rcd);
        }
    }
};
