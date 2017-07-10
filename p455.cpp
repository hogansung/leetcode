class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng = g.size();
        int ns = s.size();
        
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());

        int ts = 0;
        int cnt = 0;
        for (int i = 0; i < ng; i++) {
            if (ts < ns and s[ts] >= g[i]) {
                ts += 1;
                cnt += 1;
            } else {
                // do nothing
            }
        }
        return cnt;
    }
};
