/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void dfs(vector<NestedInteger>& nestedList, 
            int dep, vector<int>& sum_d, int& max_d) {
        max_d = max(max_d, dep);
        while (sum_d.size() <= dep) {
            sum_d.push_back(0);
        }
        for (auto integer : nestedList) {
            if (integer.isInteger() == true) {
                
                sum_d[dep] += integer.getInteger();
            } else {
                dfs(integer.getList(), dep+1, sum_d, max_d);
            }
        }
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> sum_d;
        int max_d = 0;
        dfs(nestedList, 0, sum_d, max_d);
        
        int ret = 0;
        for (int i = 0; i <= max_d; i++) {
            ret += sum_d[i] * (max_d + 1 - i);
        }
        return ret;
    }
};
