class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        
        vector<int> sum(n+1, 0);
        string str = "";
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + strs[i].length();
            
            string rev_s = strs[i];
            reverse(rev_s.begin(), rev_s.end());
            if (rev_s > strs[i]) {
                str += rev_s;
            } else {
                str += strs[i];
            }
        }
        
        string ret = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sum[i+1] - sum[i]; j++) {
                {
                    string tmp = strs[i].substr(j, sum[i+1]-sum[i]-j);
                    tmp += str.substr(sum[i+1], sum[n] - sum[i+1]);
                    tmp += str.substr(0, sum[i]);
                    tmp += strs[i].substr(0, j);
                    ret = max(ret, tmp);
                }
                {
                    string rev_s = strs[i];
                    reverse(rev_s.begin(), rev_s.end());
                    
                    string tmp = rev_s.substr(j, sum[i+1]-sum[i]-j);
                    tmp += str.substr(sum[i+1], sum[n] - sum[i+1]);
                    tmp += str.substr(0, sum[i]);
                    tmp += rev_s.substr(0, j);
                    ret = max(ret, tmp);
                }
            }
        }
        return ret;
    }
};
