class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int mmax = 0;
        int idx = -1;
        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; i++) {
            if (height[i] > mmax) {
                mmax = height[i];
                idx = i;
            }
            sum[i+1] = sum[i] + height[i];
        }
        if (idx == -1) {
            return 0;
        }
        
        int ret = 0;
        { // left to right
            stack<pair<int,int>> st;
            for (int i = 0; i <= idx; i++) {
                if (st.size() == 0 or st.top().first <= height[i]) {
                    st.emplace(height[i], i);
                }
            }
            
            if (st.size()) {
                pair<int,int> sp = st.top(); st.pop();
                while (st.size()) {
                    pair<int,int> fp = st.top(); st.pop();
                    
                    ret += fp.first * (sp.second - fp.second);
                    ret -= sum[sp.second] - sum[fp.second];
                    sp = fp;
                }
            }
        }
        { // right to left
            stack<pair<int,int>> st;
            for (int i = n-1; i >= idx; i--) {
                if (st.size() == 0 or st.top().first <= height[i]) {
                    st.emplace(height[i], i);
                }
            }
            
            if (st.size()) {
                pair<int,int> fp = st.top(); st.pop();
                while (st.size()) {
                    pair<int,int> sp = st.top(); st.pop();
                    ret += sp.first * (sp.second - fp.second);
                    ret -= sum[sp.second+1] - sum[fp.second+1];
                    fp = sp;
                }
            }
        }
        return ret;
    }
};
