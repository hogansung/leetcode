class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }
    
    double next(int val) {
        qv.push(val);
        sum += val;
        if (qv.size() > n) {
            sum -= qv.front(); qv.pop();
        }
        return sum / qv.size();
    }
    
    queue<int> qv;
    int n;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
