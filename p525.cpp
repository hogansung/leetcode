class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        
        int sum = 0;
        int mmax = 0;
        for (int i = 0; i < n; i++) {
            if (um.find(sum) == um.end()) {
                um[sum] = i;
            } 

            if (nums[i] == 0) {
                sum -= 1;
            } else {
                sum += 1;
            }
            
            if (um.find(sum) != um.end()) {
                mmax = max(mmax, i - um[sum] + 1);
            }
        }
        return mmax;
    }
};
