class Solution {
public:
    int quickCal(int fv, int sv, char op) {
        if (op == '+') {
            return fv + sv;
        } else if (op == '-') {
            return fv - sv;
        } else if (op == '*') {
            return fv * sv;
        } else {
            return fv / sv;
        }
    }
    
    int calculate(string s) {
        stack<char> st_op;
        stack<int> st_val;
        
        string s_val;
        for (char c : s) {
            if (c >= '0' and c <= '9') {
                s_val.push_back(c);
            } else {
                if (s_val.length() > 0) {
                    st_val.push(strtol(s_val.c_str(), 0, 10));
                    s_val = "";
                }
                
                if (c == '+' or c == '-') {
                    while (st_op.size()) {
                        int op = st_op.top(); st_op.pop();
                        int sv = st_val.top(); st_val.pop();
                        int fv = st_val.top(); st_val.pop();
                        st_val.push(quickCal(fv, sv, op));
                    }
                    st_op.push(c);
                } else if (c == '*' or c == '/') {
                    while (st_op.size() and
                           (st_op.top() == '*' or st_op.top() == '/')) {
                        int op = st_op.top(); st_op.pop();
                        int sv = st_val.top(); st_val.pop();
                        int fv = st_val.top(); st_val.pop();
                        st_val.push(quickCal(fv, sv, op));
                    }
                    st_op.push(c);
                }
            }
        }
        
        if (s_val.length() > 0) {
            st_val.push(strtol(s_val.c_str(), 0, 10));
        }
        
        while (st_op.size()) {
            int op = st_op.top(); st_op.pop();
            int sv = st_val.top(); st_val.pop();
            int fv = st_val.top(); st_val.pop();
            st_val.push(quickCal(fv, sv, op));
        }
        
        assert(st_val.size() == 1);
        return st_val.top();
    }
};
