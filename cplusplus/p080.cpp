class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int l = 0;
        int val = nums[0];
        int cnt = 0;
		for (int r = 0; r < n; r++) {
            if (nums[r] == val) {
                if (cnt < 2) {
                    nums[l] = val;
                    l += 1;
                    cnt += 1;
                }
            } else {
                val = nums[r];
                nums[l] = val;
                l += 1;
                cnt = 1;
            }
        }
        return l;
    }
};
