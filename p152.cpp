class Solution {
public:
    int maxProductWOZero(vector<int>& vct) {
        int n = vct.size();
        int mmax = INT_MIN;
        
        vector<int> neg_idx_vct;
        vector<int> mul(1, 1);
        
        for (int i = 0; i < n; i++) {
            if (vct[i] < 0) {
                neg_idx_vct.push_back(i);
            }
            mul.push_back(mul.back() * vct[i]);
        }
        
        mmax = max(mmax, mul.back());
        if (neg_idx_vct.size() % 2 == 1) {
            int f_idx = neg_idx_vct.front();
            if (f_idx != 0) {
                mmax = max(mmax, mul[f_idx]);
            }
            if (f_idx != n-1) {
                mmax = max(mmax, mul.back() / mul[f_idx+1]);
            }
            
            int s_idx = neg_idx_vct.back();
            if (s_idx != 0) {
                mmax = max(mmax, mul[s_idx]);
            }
            if (s_idx != n-1) {
                mmax = max(mmax, mul.back() / mul[s_idx+1]);
            }
        }
        return mmax;
    }
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mmax = INT_MIN;
        
        vector<vector<int>> vvct;
        vector<int> vct;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                mmax = max(mmax, 0);
                if (vct.size() > 0) {
                    vvct.emplace_back(vct);
                    vct = vector<int>();
                }
            } else {
                vct.push_back(nums[i]);
            }
        }
        if (vct.size() > 0) {
            vvct.emplace_back(vct);
        }
        
        for (auto vct : vvct) {
            mmax = max(mmax, maxProductWOZero(vct));
        }
        return mmax;
    }
};
