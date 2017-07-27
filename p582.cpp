class Solution {
public:
    void dfs(vector<int>& ret, int t, 
             unordered_map<int, vector<int>*>& um) {
        ret.push_back(t);
        for (auto v : (*um[t])) {
            dfs(ret, v, um);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>*> um;
        
        for (int i = 0; i < n; i++) {
            int c = pid[i];
            if (um.find(c) == um.end()) {
                um[c] = new vector<int>();
            }
                
            int p = ppid[i];
            if (um.find(p) == um.end()) {
                um[p] = new vector<int>();
            }
            
            um[p]->push_back(c);
        }
        
        vector<int> ret;
        dfs(ret, kill, um);
        return ret;
    }
};
