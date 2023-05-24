class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        
        stack<pair<int,int>> st;
        for (int i = 0; i < 2 * n; i++) {
            while (st.size() and st.top().first < nums[i%n]) {
                auto p = st.top(); st.pop();
                if (p.second < n) {
                    ret[p.second] = nums[i%n];
                }
            }
            st.emplace(nums[i%n], i);
        }
        return ret;
    }
};
