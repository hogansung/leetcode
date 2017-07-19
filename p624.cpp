class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        
        pair<int,int> mmin = make_pair(INT_MAX, -1);
        pair<int,int> smin = make_pair(INT_MAX, -1);
        for (int i = 0; i < n; i++) {
            pair<int,int> pv = make_pair(arrays[i].front(), i);
            if (pv <= mmin) {
                smin = mmin;
                mmin = pv;
            } else if (pv < smin) {
                smin = pv;
            }
        }
            
        pair<int,int> mmax = make_pair(INT_MIN, -1);
        pair<int,int> smax = make_pair(INT_MIN, -1);
        for (int i = 0; i < n; i++) {
            pair<int,int> pv = make_pair(arrays[i].back(), i);
            if (pv >= mmax) {
                smax = mmax;
                mmax = pv;
            } else if (pv > smax) {
                smax = pv;
            }
        }
        
        if (mmax.second == mmin.second) {
            return max(mmax.first - smin.first,
                       smax.first - mmin.first);
        } else {
            return mmax.first - mmin.first;
        }
    }
};
