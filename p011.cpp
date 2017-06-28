class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        // left to right
        deque<pair<int,int>> dq_l;
        for (int i = 0; i < n; i++) {
            if (dq_l.size() == 0 or dq_l.back().first < height[i]) {
                dq_l.emplace_back(height[i], i);
            }
        }
        
        // right to left
        deque<pair<int,int>> dq_r;
        for (int i = n-1; i >= 0; i--) {
            if (dq_r.size() == 0 or dq_r.back().first < height[i]) {
                dq_r.emplace_back(height[i], i);
            }
        }
        
        int mmax = 0;
        while (dq_l.size() and dq_r.size()) {
            if (dq_l.front().first < dq_r.front().first) {
                mmax = max(mmax, dq_l.front().first * (dq_r.front().second - dq_l.front().second));
                dq_l.pop_front();
            } else {
                mmax = max(mmax, dq_r.front().first * (dq_r.front().second - dq_l.front().second));
                dq_r.pop_front();
            }
        }
        return mmax;
    }
};
