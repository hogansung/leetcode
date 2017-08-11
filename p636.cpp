class Solution {
public:
    void split(vector<string>& vct, string& log) {
        stringstream ss(log);
        string str;
        while (getline(ss, str, ':')) {
            vct.emplace_back(str);
        }
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        
        stack<pair<int,int>> st;
        for (auto log : logs) {
            vector<string> vct;
            split(vct, log);
            
            int tag = strtol(vct[0].c_str(), 0, 10);
            bool start = vct[1] == "start" ?true :false;
            int time = strtol(vct[2].c_str(), 0, 10);
            
            if (start == true) {
                st.emplace(tag, time);
            } else {
                int sum = 0;
                pair<int,int> pv;
                do {
                    pv = st.top(); st.pop();
                    if (pv.first != tag) {
                        assert(pv.first == -1);
                        sum += pv.second;
                    }
                } while (pv.first != tag);
                
                int val = time - pv.second + 1;
                ret[tag] += val - sum;
                st.emplace(-1, val);
            }
        }
        
        return ret;
    }
};
