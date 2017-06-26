class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        
        int mmax = 0;
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(-1);
            } else {
                int val = 0;
                while (st.size() and st.top() != -1) {
                    val += st.top();
                    st.pop();
                }
                mmax = max(mmax, val);
                if (st.size() and st.top() == -1) {
                    st.pop();
                    st.push(val+2);
                }
            }
        }
        
        int val = 0;
        while (st.size()) {
            if (st.top() == -1) {
                mmax = max(mmax, val);
                val = 0;
            } else {
                val += st.top();
            }
            st.pop();
        }
        mmax = max(mmax, val);
        return mmax;
    }
};
