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
    struct myCMP {
        bool operator()(const Interval& a, const Interval& b) {
            if (a.start == b.start) {
                return a.end < b.end;
            } else {
                return a.start < b.start;
            }
        }
    };
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myCMP());
        
        int rb = INT_MIN;
        for (auto interval : intervals) {
            if (rb > interval.start) {
                return false;
            }
            rb = interval.end;
        }
        return true;
    }
};
