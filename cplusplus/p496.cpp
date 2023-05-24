lass Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n1 = findNums.size();
        int n2 = nums.size();
        
        unordered_map<int,int> um;
        stack<int> st;
        for (int i = 0; i < n2; i++) {
            while (st.size() and st.top() < nums[i]) {
                int val = st.top(); st.pop();
                um[val] = nums[i];
            }
            st.push(nums[i]);
        }
        while (st.size()) {
            int val = st.top(); st.pop();
            um[val] = -1;
        }
        
        vector<int> ret;
        for (int i = 0; i < n1; i++) {
            ret.push_back(um[findNums[i]]);
        }
        return ret;
    }
};
