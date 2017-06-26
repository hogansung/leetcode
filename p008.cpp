class Solution {
public:
    int myAtoi(string str) {
        // hack: it is not interesting to solve this
        long long ret = strtoll(str.c_str(), 0, 10);
        ret = max(ret, 1LL * INT_MIN);
        ret = min(ret, 1LL * INT_MAX);
        return ret;
    }
};
