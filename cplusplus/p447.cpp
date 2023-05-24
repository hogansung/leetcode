class Solution {
public:
    double calDis(pair<int,int>& pf, pair<int,int>& ps) {
        double dx = pf.first - ps.first;
        double dy = pf.second - ps.second;
        return dx * dx + dy * dy;
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double,int> um;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    // do nothing
                } else {
                    double val = calDis(points[i], points[j]);
                    um[val] += 1;
                }
            }
            
            for (auto p : um) {
                cnt += p.second * (p.second-1);
            }
        }
        
        return cnt;
    }
};
