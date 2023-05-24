class Solution {
public:
    void dfs(vector<string>& ret,
             vector<bool>& st, int t, int num) {
        if (t == 10) {
            if (num == 0) {
                int hr = 0;
                for (int i = 0; i < 4; i++) {
                    if (st[i] == true) {
                        hr += (1 << i);
                    }
                }
                int mn = 0;
                for (int i = 0; i < 6; i++) {
                    if (st[4+i] == true) {
                        mn += (1 << i);
                    }
                }
                
                if (hr < 12 and mn < 60) {
                    char tmp[6];
                    sprintf(tmp, "%d:%02d", hr, mn);
                    ret.emplace_back(tmp);
                }
            }
        } else {
            dfs(ret, st, t+1, num);
            
            st[t] = true;
            dfs(ret, st, t+1, num-1);
            st[t] = false;
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        vector<bool> st(10, false);
        dfs(ret, st, 0, num);
        return ret;
    }
};
