long long INF = 1000000000;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n == 0) {
            return true;
        } else {
            map<pair<int,int>, int> mp;
            for (auto point : points) {
                mp[point] = 1;
            }
            
            int x_lb = mp.begin()->first.first;
            int x_rb = mp.rbegin()->first.first;
            double x_split = 0.5 * (x_lb + x_rb);

            bool suc = true;
            for (auto p : mp) {
                int cnt_l = p.second;
                int cnt_r = mp[make_pair(2 * x_split - p.first.first, p.first.second)];
                suc &= (cnt_l == cnt_r);
            }
            return suc;
        }
    }
};
