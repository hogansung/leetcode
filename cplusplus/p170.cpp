class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        // do nothing
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        s_um[number] += 1;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto p : s_um) {
            if (value - p.first == p.first) {
                if (p.second >= 2) {
                    return true;
                } else {
                    // do nothing
                }
            } else if (s_um.count(value-p.first) > 0) {
                return true;
            }
        }
        return false;
    }
    
    unordered_map<int,int> s_um;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
