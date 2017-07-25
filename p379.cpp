class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        used = valid = unordered_set<int>();
        for (int i = 0; i < maxNumbers; i++) {
            valid.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (valid.size() == 0) {
            return -1;
        } else {
            int val = *(valid.begin());
            valid.erase(val);
            used.insert(val);
            return val;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return used.find(number) == used.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
        valid.insert(number);
    }
    
    unordered_set<int> used;
    unordered_set<int> valid;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
