class Solution {
public:
    int calDist(pair<int,int>& p1, pair<int,int>& p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>> vct;
        vct.emplace_back(p1[0], p1[1]);
        vct.emplace_back(p2[0], p2[1]);
        vct.emplace_back(p3[0], p3[1]);
        vct.emplace_back(p4[0], p4[1]);
        
        int n = vct.size();
        unordered_map<int,int> um;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                um[calDist(vct[i], vct[j])] += 1;
            }
        }
        
        vector<int> res;
        for (auto p : um) {
            res.push_back(p.second);
        }
        return res.size() == 2 and
               (res[0] == 2 or res[1] == 2);
    }
};
