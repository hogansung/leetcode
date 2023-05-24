class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' or c == '[' or c == '{') {
                st.push(c);
            } else if (c == ')') {
                if (st.size() and st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (st.size() and st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (st.size() and st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (st.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};
