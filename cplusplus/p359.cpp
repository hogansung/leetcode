class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        // do nothing
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (um.find(message) == um.end()) {
            um[message] = timestamp;
            return true;
        } else if (timestamp - um[message] >= 10) {
            um[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
    
    unordered_map<string,int> um;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
