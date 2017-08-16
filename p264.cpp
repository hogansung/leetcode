class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vct = {2, 3, 5};
        
        unordered_set<long long> us;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        us.insert(1);
        pq.push(1);
        for (; n > 1; n--) {
            long long t = pq.top(); pq.pop();
            for (int i = 0; i < 3; i++) {
                long long val = t * vct[i];
                if (us.find(val) == us.end()) {
                    us.insert(val);
                    pq.push(val);
                }
            }
        }
        return pq.top();
    }
};
