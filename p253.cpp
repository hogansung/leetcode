/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> vct;
        for (auto interval : intervals) {
            vct.emplace_back(interval.start, 1);
            vct.emplace_back(interval.end, -1);
        }
        
        sort(vct.begin(), vct.end());
        
        int sum = 0;
        int mmax = 0;
        for (auto pv : vct) {
            sum += pv.second;
            mmax = max(mmax, sum);
        }
        return mmax;
    }
};
