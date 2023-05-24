class Solution {
public:
    bool check(vector<int>& citations, int k) {
        int cnt = 0;
        for (auto val : citations) {
            if (val >= k) {
                cnt += 1;
            }
        }
        return cnt >= k;
    }
    
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size();
        while (l < r) {
            int m = (l + r) / 2 + 1;
            if (check(citations, m) == true) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
