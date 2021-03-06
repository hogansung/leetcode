class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        qv = queue<int>();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        qv.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (qv.size() and qv.front() + 300 <= timestamp) {
            qv.pop();
        }
        return qv.size();
    }
    
    queue<int> qv;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
