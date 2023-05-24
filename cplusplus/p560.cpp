class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            um[sum] += 1;
            sum += nums[i];
            cnt += um[sum - k];
        }
        return cnt;
    }
};
