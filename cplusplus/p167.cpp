class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        while (l < r) {
            if (numbers[l] + numbers[r] < target) {
                l += 1;
            } else if (numbers[l] + numbers[r] > target) {
                r -= 1;
            } else {
                vector<int> ret;
                ret.push_back(l+1);
                ret.push_back(r+1);
                return ret;
            }
        }
		assert(false);
    }
};
