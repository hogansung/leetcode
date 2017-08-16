class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> vct;
        for (auto timePoint : timePoints) {
            int h, m;
            sscanf(timePoint.c_str(), "%d:%d", &h, &m);
            vct.push_back(60 * h + m);
        }
        
        sort(vct.begin(), vct.end());
        int mmin = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            mmin = min(mmin, vct[i+1] - vct[i]);
        }
        mmin = min(mmin, vct[0] + 24 * 60 - vct[n-1]);
        
        return mmin;
    }
};
