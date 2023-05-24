class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto token : tokens) {
            if (token.length() > 1 or (token[0] >= '0' and token[0] <= '9')) {
                st.emplace(strtol(token.c_str(), 0, 10));
            } else {
                assert(st.size() >= 2);
                int sval = st.top(); st.pop();
                int fval = st.top(); st.pop();
                
                if (token == "+") {
                    st.emplace(fval + sval);
                } else if (token == "-") {
                    st.emplace(fval - sval);
                } else if (token == "*") {
                    st.emplace(fval * sval);
                } else if (token == "/") {
                    st.emplace(fval / sval);
                } else {
                    assert(false);
                }    
            }
        }
        assert(st.size() == 1);
        return st.top();
    }
};
