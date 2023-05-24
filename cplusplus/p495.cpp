class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int last = -1;
        int sum = 0;
        for (auto time : timeSeries) {
            if (last != -1) {
                sum += min(time - last, duration);
            }
            last = time;
        }
        if (last != -1) {
            sum += duration;
        }
        return sum;
    }
};
