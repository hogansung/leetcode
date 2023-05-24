class Solution {
public:
    string parseTernary(string expression) {
        int len = expression.length();
        vector<int> tab(len, -1);
        
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (expression[i] == '?') {
                st.push(i);
            } else if (expression[i] == ':') {
                assert(st.size() > 0);
                tab[st.top()] = i;
                st.pop();
            }
        }
        assert(st.size() == 0);
        
        int l = 0;
        int r = len - 1;
        while (l < r) {
            if (expression[l] == 'T') {
                r = tab[l+1]-1;
                l += 2;
            } else {
                l = tab[l+1]+1;
            }
        }
        return expression.substr(l, 1);
    }
};
