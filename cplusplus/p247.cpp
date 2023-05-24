class Solution {
public:
    vector<int> f_candidates;
    vector<int> b_candidates;
    
    void dfs(vector<string>& ret, string& fs, 
             string& bs, int t, const int n) {
        if (t == n/2) {
            reverse(bs.begin(), bs.end());
            if (n % 2 == 0) {
                ret.emplace_back(fs + bs);
            } else {
                ret.emplace_back(fs + "0" + bs);
                ret.emplace_back(fs + "1" + bs);
                ret.emplace_back(fs + "8" + bs);
            }
            reverse(bs.begin(), bs.end());
        } else {
            for (int i = 0; i < 5; i++) {
                if (t == 0 and i == 0) {
                    continue;
                }
                fs.push_back('0' + f_candidates[i]);
                bs.push_back('0' + b_candidates[i]);
                dfs(ret, fs, bs, t+1, n);
                fs.pop_back();
                bs.pop_back();
            }
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        f_candidates = vector<int>{0, 1, 6, 8, 9};
        b_candidates = vector<int>{0, 1, 9, 8, 6};
        
        vector<string> ret;
        string fs;
        string bs;
        dfs(ret, fs, bs, 0, n);
        return ret;
    }
};
