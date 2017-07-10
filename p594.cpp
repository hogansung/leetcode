class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for (auto num : nums) {
            m[num] += 1;
        }
        
        int n = nums.size();
        int mmax = 0;
        for (auto p : m) {
            if (m.find(p.first+1) != m.end()) {
                mmax = max(mmax, p.second + m[p.first+1]);
            }
        }
        return mmax;
    }
};
