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
    struct IntervalCmp {
        bool operator()(Interval& a, Interval& b) {
            if (a.start == b.start) {
                return a.end < b.end;
            } else {
                return a.start < b.start;
            }
        }
    };

    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return vector<Interval>();
        } else {
            sort(intervals.begin(), intervals.end(), IntervalCmp());
            
            vector<Interval> ret;
            int l = intervals[0].start;
            int r = intervals[0].end;
            for (int i = 1; i < n; i++) {
                if (intervals[i].start <= r) {
                    r = max(r, intervals[i].end);
                } else {
                    ret.emplace_back(l, r);
                    l = intervals[i].start;
                    r = intervals[i].end;
                }
            }
            ret.emplace_back(l, r);
            
            return ret;
        }
    }
};
